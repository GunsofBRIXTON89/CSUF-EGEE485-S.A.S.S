// ============================================================================
// File: Sensors_And_Measurement.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation for the Sensors_And_Measurements Class
// ============================================================================
#include"Sensors_And_Measurements.h"


// === Validate_Key ===========================================================
//
// Everytime the Sensors_And_Measurement object wants to use the I2C line,
// it must first call on this function to confirm it has exclusive access to 
// the I2C line.
//
// ============================================================================
//bool	Sensors_And_Measurement::Validate_Key() {
//	return( sensor_key == sensor_I2C->Get_Access_Key() );
	
//} // end of Validate_Key