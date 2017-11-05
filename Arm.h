// ============================================================================
// File: Arm.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Arm Class
// ============================================================================
#include"Gpio.h"
#include"I2CDevice.h"

#pragma once // designed to cause the current source file to be included once
//  for compilation

class Arm{
public:
	Arm() :arm_I2C(NULL) {}
	Arm(exploringRPi::I2CDevice *I2C_Ref) { arm_I2C = I2C_Ref; }

	bool Validate_Key();

private:
	const string arm_key = ARMKEY;
	exploringRPi::I2CDevice	*arm_I2C;

}; // end of Arm Class