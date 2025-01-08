#pragma once

#ifdef FPPWRSENSORDLL_EXPORTS		// <LIBNAME>_EXPORT
#define PWRSENSOR_API __declspec(dllexport)
#else
#define PWRSENSOR_API __declspec(dllimport)
#endif

enum class INA232_Register
{
	CONFIG_REG		= 0x00,		// R/W
	SHUNT_VOLT_REG	= 0x01,		// R
	BUS_VOLT_REG	= 0x02,		// R
	POWER_REG		= 0x03,		// R
	CURRENT_REG		= 0x04,		// R
	CALIB_REG		= 0x05,		// R/W
	MASK_EN_REG		= 0x06,		// R/W
	ALERT_LIMT_REG	= 0x07,		// R/W
	MANUF_ID_REG	= 0x3E		// R
};

/**
* Face Pod Power Sensor
*/
class FpPowerSensor {
private:
	unsigned int i2cSpeed = 400;
	unsigned int i2cAddr = 0x4B;
	const char* bus = "user";
	int16_t _twos_compliment_to_int(int16_t val, uint8_t bits);
	double _Current_LSB = 0.000500;		// 500 uA/LSB  = ~ _I_max / pow(2.0, 15.0) x 8;
	double _I_max = 10.0;				// 10 A expected max current
	double _BusVoltageStep = 0.0016;	// 1.6 mV/step
	double _ShutVoltStep_R0 = 0.0000025;	// 2.5 uV/step ADCRANGE=0
	double _ShutVoltStep_R1 = 0.0000000625;	// 625 nV/step ADCRANGE=1	

public:
	FpPowerSensor();
	double getCurrent();
	double getBusVoltage();
	double getShuntVoltage();
	double getPower();
	uint16_t getRegister(INA232_Register reg);
};

// Helper methods for constructor and exported methods
extern "C" PWRSENSOR_API FpPowerSensor* FpPwr_Instantiate();
extern "C" PWRSENSOR_API double FpPwr_getPower(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getShuntVoltage(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getBusVoltage(FpPowerSensor* p);
extern "C" PWRSENSOR_API double FpPwr_getCurrent(FpPowerSensor* p);
