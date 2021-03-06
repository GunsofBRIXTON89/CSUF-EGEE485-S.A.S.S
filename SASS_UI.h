// ============================================================================
// File: SASS_UI.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for Container Class
// ============================================================================
#include "Motor.h"
#include "Arm.h"
#include "Claw.h"
#include "Sensors_And_Measurements.h"
#include "Storage_System.h"
#include "I2CDevice.h"

using namespace std;



#pragma once // designed to cause the current source file to be included once
//  for compilation

class SASS_UI{
public:
	void SASS_UI();

private:
	Arm							arm;
	Motor						motors;
	Claw						claw;
	Storage_System				ss;
	Sensors_And_Measurement		snm;
	exploringRPi::I2CDevice		myI2CDevice;
	int							myI2C_lock;
	
	
}; // end of SASS_UI Class