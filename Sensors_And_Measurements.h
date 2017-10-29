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
using namespace std;
#pragma once // designed to cause the current source file to be included once
//  for compilation

class Sensors_And_Measurement: public exploringRPi::GPIO{
public:
	Sensors_And_Measurement(){ cout << " Sensors_And_Measurement ctor\n"; } //' default ctor
private:

}; // end of Sensors_And_Measurement Class