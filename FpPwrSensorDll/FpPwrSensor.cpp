#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <iostream>
#include <iomanip>
#include <format>
#include <Windows.h>

#include "FpPwrSensor.h"
#include "MSCI2C.h"

FpPowerSensor::FpPowerSensor()
{
	// Configure Sensor:
	// Initialize for continous 
    bool ret;
    unsigned int offset = 0;
    unsigned int nbrBytes = 2;
    UCHAR ioBuf[10];
    unsigned int bytesWritten;
    unsigned int bytesRead;
    unsigned short deviceID;

    // check that INA232 chip is present
    printf("Checking for INA232 chip\n");
    offset = (unsigned int)INA232_Register::MANUF_ID_REG;
    ret = read1(bus, i2cAddr, i2cSpeed, offset, nbrBytes, ioBuf, &bytesRead);
    if (ret)
    {
        printf("We read %u bytes from i2c=0x%02X and returned 0x%02X%02X\n", bytesRead, i2cAddr, ioBuf[0], ioBuf[1]);
    }
    else
    {
        printf("No INA232 chip present at address: 0x%02X\n", i2cAddr);
    }
    deviceID = (ioBuf[0] << 8) + ioBuf[1];
    if (deviceID == 0x5449) {
        printf("INA232 Sensor at 0x%02X found\n", i2cAddr);
    }
    else {
        throw std::runtime_error("No INA232 Sensor found");
    }

    // Configure for continous operation @ 1100 usec, ADCRANGE=1
    offset = (unsigned int)INA232_Register::CONFIG_REG;
    ioBuf[0] = 0x55;
    ioBuf[1] = 0x27;
    ret = write1(bus, i2cAddr, i2cSpeed, offset, ioBuf, 2, &bytesWritten);
    if (ret)
        printf("Configured sensor at 0x%02X for continuous conversion\n", i2cAddr);
    else
        printf("Write failed\n");
    ret = read1(bus, i2cAddr, i2cSpeed, offset, 2, ioBuf, &bytesRead);
    if (ret)
        printf("We read %u bytes from i2c=0x%02X and returned 0x%02X%02X\n", bytesRead, i2cAddr, ioBuf[0], ioBuf[1]);

    // Configure the SHUNT_CAL value (for ADCRANGE=1, SHUNT_CAL=0x0100)
    offset = (unsigned int)INA232_Register::CALIB_REG;
    ioBuf[0] = 0x01;
    ioBuf[1] = 0x00;
    ret = write1(bus, i2cAddr, i2cSpeed, offset, ioBuf, 2, &bytesWritten);
    if (ret)
        printf("Configured sensor at 0x%02X for continuous conversion\n", i2cAddr);
    else
        printf("Write failed\n");
    ret = read1(bus, i2cAddr, i2cSpeed, offset, 2, ioBuf, &bytesRead);
    if (ret)
        printf("We read %u bytes from i2c=0x%02X and returned 0x%02X%02X\n", bytesRead, i2cAddr, ioBuf[0], ioBuf[1]);

}

// Convert input two's compliment value to specified # of bits
int16_t FpPowerSensor::_twos_compliment_to_int(int16_t val, uint8_t bits)
{
    if ((val & (1 << (bits - 1))) != 0)
        val = val - (1 << bits);
    
    return val;
}

uint16_t FpPowerSensor::getRegister(INA232_Register reg)
{
    bool ret;
    unsigned int nbrBytes = 2;
    UCHAR ioBuf[10];
    unsigned int bytesRead;
    uint16_t val = 0;
    unsigned int ureg;

    ureg = (unsigned int)reg;
    // read the specified Sensor over I2C interface
    memset(ioBuf, 0, sizeof(ioBuf));
    ret = read1(bus, i2cAddr, i2cSpeed, ureg, nbrBytes, ioBuf, &bytesRead);
    if (!ret)
        printf("We read %u bytes and returned 0x%02X%02X\n", bytesRead, ioBuf[0], ioBuf[1]);
    else
        printf("Read failed\n");

    val = (ioBuf[0] << 8) + ioBuf[1];
    printf("Register 0x%02X = %u (0x%0X)\n", ureg, val, val);

    return val;
}

double FpPowerSensor::getCurrent()
{
    signed short rawcurrent;
    bool sign_bit = false;
    double current = 0.0;

    // average current in Amperes is returned as a Two's compliment value
    rawcurrent = (signed short)getRegister(INA232_Register::CURRENT_REG);
    printf("Raw Current is %d (0x%0X)\n", rawcurrent, rawcurrent);
    sign_bit = rawcurrent >> 15;
    if (sign_bit)
        current = _twos_compliment_to_int(rawcurrent, 16) * _Current_LSB;
    else
        current = rawcurrent * _Current_LSB;
    printf("Current = %.2f A\n", current);

    return current;
}

double FpPowerSensor::getBusVoltage()
{
    uint16_t rawbusvolt = 0;
    double busvolt = 0.0;

    rawbusvolt = getRegister(INA232_Register::BUS_VOLT_REG);
    busvolt = _BusVoltageStep * rawbusvolt;
    printf("BUS Voltage: %.2f Volts\n", busvolt);

    return busvolt;
}

double FpPowerSensor::getShuntVoltage()
{
    uint16_t rawshuntvolt = 0;
    double shuntvolt = 0.0;

    rawshuntvolt = getRegister(INA232_Register::SHUNT_VOLT_REG);
    shuntvolt = _ShutVoltStep_R1 * rawshuntvolt;
    printf("SHUNT Voltage: %.2f Volts\n", shuntvolt);

    return shuntvolt;
}

double FpPowerSensor::getPower()
{
    uint16_t rawpower = 0;
    double power = 0.0;

    rawpower = getRegister(INA232_Register::POWER_REG);
    power = _Current_LSB * 32.0 * rawpower;

    printf("Power %.2f Watts\n", power);

    return power;
}

// Helper methods for constructor and exported methods
extern "C" PWRSENSOR_API FpPowerSensor* FpPwr_Instantiate()
{
    return new FpPowerSensor();
}

extern "C" PWRSENSOR_API double FpPwr_getPower(FpPowerSensor* p)
{
    return p->getPower();
}

extern "C" PWRSENSOR_API double FpPwr_getShuntVoltage(FpPowerSensor* p)
{
    return p->getShuntVoltage();
}

extern "C" PWRSENSOR_API double FpPwr_getBusVoltage(FpPowerSensor* p)
{
    return p->getBusVoltage();
}

extern "C" PWRSENSOR_API double FpPwr_getCurrent(FpPowerSensor* p)
{
    return p->getCurrent();
}
