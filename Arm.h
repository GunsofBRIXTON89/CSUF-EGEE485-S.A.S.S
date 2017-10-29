// ============================================================================
// File: Arm.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Arm Class
// ============================================================================
#include<iostream>
#include"Gpio.h"
using namespace std;
#pragma once // designed to cause the current source file to be included once
//  for compilation

class Arm:public exploringRPi::GPIO{
public:
	Arm(){ cout << "Default Arm ctor\n"; }
private:

}; // end of Arm Class