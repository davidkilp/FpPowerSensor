// FpPowerSensor.cpp : Configure and Read TI INA232BIDDFR Digital Power Monitor
// chip on CPU I2C bus
//

#include <iostream>
#include <Windows.h>


#include "FpPwrSensor.h"

int main()
{
    std::cout << "Facepod Power Sensor Test Start\n";

    // initialize Sensor
    FpPowerSensor *pSensor = FpPwr_Instantiate();

    while (1) {
        std::cout << "BUS Voltage: " << FpPwr_getBusVoltage(pSensor) << " V" << std::endl;
        std::cout << "SHUNT Voltage: " << FpPwr_getShuntVoltage(pSensor) << " V" << std::endl;
        std::cout << "Current: " << FpPwr_getCurrent(pSensor) << " A" << std::endl;
        std::cout << "Power: " << FpPwr_getPower(pSensor) << " Watts" << std::endl;

        Sleep(1000);
    }

    return 0;
}
