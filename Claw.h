// ============================================================================
// File: Claw.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Claw Class
// ============================================================================

#include"Gpio.h"
#include"I2CDevice.h"

#pragma once // designed to cause the current source file to be included once
//  for compilation

class Claw{
public:
	Claw() :claw_I2C(NULL) {}
	Claw(exploringRPi::I2CDevice *I2C_Ref){ claw_I2C = I2C_Ref; }
	bool Validate_Key();
	// TODO: ===============================================
	void	Open_Claw();
	void	Close_Claw(); // should have a set value to to grab same thickness of shelves

	void	Fold();
	void	Unfold();

	void	Push_Claw(); 
	void	Pull_Claw();
	// =====================================================


private:
	const string				claw_key = CLAWKEY;
	exploringRPi::I2CDevice				 *claw_I2C;	

}; // end of Claw Class