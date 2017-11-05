// ============================================================================
// File: Sensors_And_Measurement.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Sensors_And_Measurements Class
// ============================================================================

#include"Gpio.h"
#include"I2CDevice.h"

#pragma once // designed to cause the current source file to be included once
//  for compilation

class Sensors_And_Measurement{
public:
	Sensors_And_Measurement() :sensor_I2C(NULL) {}
	Sensors_And_Measurement(exploringRPi::I2CDevice *I2C_Ref) { sensor_I2C = I2C_Ref; }
	
	bool Validate_Key();

private:
	const string	sensor_key = SENSORKEY;
	exploringRPi::I2CDevice	   *sensor_I2C;
}; // end of Sensors_And_Measurement Class