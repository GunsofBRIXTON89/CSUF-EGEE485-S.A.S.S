// ============================================================================
// File: Motor.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Motor Class 
// ============================================================================

#include"Gpio.h"
#include"I2CDevice.h"
using namespace std;
#pragma once // designed to cause the current source file to be included once
//  for compilation

#define MOTORKEY "vroom!"

#define GPIO13 33 // pulldown - GPIO# [Physical pin] 
#define GPIO19 35 // pulldown
#define GPIO26 37 // pulldown
#define GPIO14 8  // pulldown
#define GPIO15 10 // pulldown
#define GPIO18 12 // pulldown
#define GPIO23 16 // pulldown
#define GPIO24 18 // pulldown

#define GPIO17 11 // Physical pin  and pulldown 
#define GPIO27 13 // pulldown
#define GPIO22 15 // pulldown
#define GPIO10 19 // pulldown
#define GPIO9  21 // pulldown
#define GPIO11 23 // pulldown
#define GPIO25 22 // pulldown
#define GPIO12 32 // pulldown

class Motor{
public:
	Motor() :motor_I2C(NULL) {}
	Motor(exploringRPi::I2CDevice *I2C_Ref) { motor_I2C = I2C_Ref };
	
	bool	Validate_Key();
	
private:
	const string motor_key = MOTORKEY;
	exploringRPi::I2CDevice	*motor_I2C;
	
	// GPIO pins for x-direction Stepper
	exploringRPi::GPIO	x_Inverted_Enable(GPIO13);
	exploringRPi::GPIO				x_MS1(GPIO19);
	exploringRPi::GPIO				x_MS2(GPIO26);
	exploringRPi::GPIO				x_MS3(GPIO14);
	exploringRPi::GPIO	 x_Inverted_Reset(GPIO15);
	exploringRPi::GPIO	 x_Inverted_Sleep(GPIO18);
	exploringRPi::GPIO			   x_Step(GPIO23);
	exploringRPi::GPIO		  x_Direction(GPIO24);

	// GPIO pins for Z-direction Stepper
	exploringRPi::GPIO	z_Inverted_Enable(GPIO17);
	exploringRPi::GPIO				z_MS1(GPIO27);
	exploringRPi::GPIO				z_MS2(GPIO22);
	exploringRPi::GPIO				z_MS3(GPIO10);
	exploringRPi::GPIO	  z_Inverted_Reset(GPIO9);
	exploringRPi::GPIO	 z_Inverted_Sleep(GPIO11);
	exploringRPi::GPIO			   z_Step(GPIO25);
	exploringRPi::GPIO		  z_Direction(GPIO12);

}; // end of Motor Class