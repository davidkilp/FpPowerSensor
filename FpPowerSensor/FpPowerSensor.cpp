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
#if 0
        // NOTE: with lower-level debugging output enabled this will not be displayed correctly
        std::cout << "BUS Voltage: " << FpPwr_getBusVoltage(pSensor) << " V" << std::endl;
        std::cout << "SHUNT Voltage: " << FpPwr_getShuntVoltage(pSensor) << " V" << std::endl;
        std::cout << "Current: " << FpPwr_getCurrent(pSensor) << " A" << std::endl;
        std::cout << "Power: " << FpPwr_getPower(pSensor) << " Watts" << std::endl;
#endif

        double val = FpPwr_getBusVoltage(pSensor);
        std::cout << "BUS Voltage: " << val << " V" << std::endl;

        val = FpPwr_getShuntVoltage(pSensor);
        std::cout << "SHUNT Voltage: " << val << " V" << std::endl;
        
        val = FpPwr_getCurrent(pSensor);
        std::cout << "Current: " << val << " A" << std::endl;
        
        val = FpPwr_getPower(pSensor);
        std::cout << "Power: " << val << " Watts" << std::endl;

        Sleep(2000);
    }

    return 0;
}
