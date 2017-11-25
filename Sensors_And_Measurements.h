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


#define GPIO4  7 // pulldown - GPIO# [Physical pin] 
#define GPIO5  29 // pulldown
#define GPIO6  31 // pulldown

enum sensor { TOP, LEFT, RIGHT };
enum mode { ON, OFF };

class Sensors_And_Measurement{
public:
	Sensors_And_Measurement():Trig01(GPIO4),Trig02(GPIO5),Trig03(GPIO6) { }
	//bool Validate_Key();

		/*
	// TODO: ==================================
	void	 Set_Trig(int distSensorNum, int val);
	void	 ReadEcho(int distSensorNum);
	double	 Calc_Distance_mm();
	void	 Get_Measurements(double &height, double &w_dia);
	double	 Calc_Volume(double height, double w_dia);
	// ========================================
    */
private:
	//const string	sensor_key = SENSORKEY;
	//exploringRPi::I2CDevice	   *sensor_I2C;
	
	// Digital Pins
	exploringRPi::GPIO						Trig01;
	exploringRPi::GPIO						Trig02;
	exploringRPi::GPIO						Trig03;

}; // end of Sensors_And_Measurement Class