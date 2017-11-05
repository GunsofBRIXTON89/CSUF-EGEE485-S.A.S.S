// ============================================================================
// File: Motor.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation of Motor Class
// ============================================================================
#include "Motor.h"



// === Validate_Key ===========================================================
//
// Everytime the Motor object wants to use the I2C line, it must first call on 
// this function to confirm it has exclusive access to the I2C line
//
// ============================================================================
bool	Motor::Validate_Key() {
	return( motor_key == motor_I2C->Get_Access_Key() );

} // end of Validate_Key


