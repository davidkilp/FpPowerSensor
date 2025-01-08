# FpPowerSensor - HID Gate Facepod on-board Power Sensor

## Summary
Provides access to the on-board TI INA232 Digital Power Monitor Sensor.

Solution includes separate builds for :

 * C++ DLL that hides all the low level details: FpPwrSensorDll.dll
 * A Cpp command line demo program that uses the DLL: FpPwrSensor.exe
 * A .NET Forms GUI demo application using the DLL through interop services: FpPowerDisplay.exe
 
The primary output is the FpPwrSensorDll.dll which can be included in users program to access the power monitor chip.

## Requirements
* Visual Studio 2022
* .NET 8 Runtime must be installed on hosted system. See: [.NET 8 Runtime Installer:](https://dotnet.microsoft.com/en-us/download/dotnet/thank-you/runtime-desktop-8.0.2-windows-x64-installer)
* MSCI2C64.dll from Avnet Embedded. This provides an PICMG Embedded Application Programming Interface (EAPI) to the I2C interface on 
	the underlying COM-Express module via A copy is included here but the original can be obtained from [[Avnet MSC EAPI NG Win10 Win11 x64](https://embedded.avnet.com/software-tools/#msc_eapi_ng])


## API

The FpPwrSensorDll.dll provides the following API for user programs:

```
extern "C" PWRSENSOR_API FpPowerSensor* FpPwr_Instantiate();
extern "C" PWRSENSOR_API double FpPwr_getPower(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getShuntVoltage(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getBusVoltage(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getCurrent(FpPowerSensor* p);
```


## Usage

Find the .NET GUI application, FpPowerDisplay.exe, and launch it. 

![screenshot](https://github.com/davidkilp/FpLtg/blob/master/FpTempDisplay_screenshot.jpg)

Click the Start button will intitiate update the data from the sensor every 2-seconds.

