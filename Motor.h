// ============================================================================
// File: Motor.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for the Motor Class 
// Note: Both Motors utilize Full-Step mode at 200 Steps per Rotation
// ============================================================================

#include"Gpio.h"
#include"pwmDriver.h"
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
#define GPIO17 11 // pulldown
#define GPIO27 13 // pulldown
#define GPIO22 15 // pulldown
#define GPIO10 19 // pulldown
#define GPIO9  21 // pulldown
#define GPIO11 23 // pulldown
#define GPIO25 22 // pulldown
#define GPIO12 32 // pulldown
// Motor Definitions
#define NUM_MOTORS 2
#define X_MOTOR 14 // Pin number on PCA9685 Breakout
#define Z_MOTOR 15 // Pin number on PCA9685 Breakout
#define X_PITCH 5 // (mm)  Horizontal Travel for one rotation
#define Z_PITCH 2 // (mm)  Vertical Travel for one rotation
#define STEPS_PER_ROTATION 200 // %50 Duty Cycle
#define STEPPER_DUTY_CYCLE 50.0 // in percentage
#define MAX_VEL 150 // in (mm/s)
#define DEFAULT_VEL 50
#define MIN_VEL 10
#define MAX_X_FREQ 6000 // in (Hz)
#define MIN_X_FREQ 2400
#define MAX_Z_FREQ 15000
#define MIN_Z_FREQ 6000
#define MAX_X_DIST_TRAVELED 400 // in (mm)
#define MIN_DIST_TRAVELED 0 
#define MAX_Z_DIST_TRAVELED 900 


enum motor{X,Z};
enum direction{Forward,Reverse};

class Motor{
public:
	// Constructor
	Motor(exploringRPi::PWMDriver *pwmDriver);

	bool	Validate_Key();
	// TODO: ===============================
	void Move_xDirection(float dir); //private
	void Move_To_Col(); // public
	void Return_xHome(); // private
	void Move_zDirection(); //private
	void Move_To_Row();
	void Return_ZHome();
	//void Set_Fullstep();  We are only using FullStep
	void Set_Direction(int motor = X, int dir = Forward);
	float Get_RPM(int motor = X) const { return rpm[motor]; }
	void Set_Dist_Travel(int motor, const float dist);
	void Set_Velocity(int vel, int motor = X);
	void Move_Motor(float distance, int motor = X, int dir = Forward);
	// =====================================

private:
	
	//void Offset_x(); // private  TODO: Consider after other functionalities are implemented
	//void Offset_z(); // private

	const string motor_key = MOTORKEY;
	int		x_OutputNumber;
	int		z_OutputNumber;
	float	rpm[NUM_MOTORS]; // Rotations of Stepper motor per minute
	float	dist[NUM_MOTORS]; // (mm) - Linear Distance travel

	float	frequency[NUM_MOTORS]; // PWM frequency
	float   velocity[NUM_MOTORS]; // in (mm/s)
	unsigned long int wait_time[NUM_MOTORS]; //in (us)
	int traveled[NUM_MOTORS];
	int screw_pitch[NUM_MOTORS];
	int curr_Motor_dir;
	

	exploringRPi::PWMDriver *pwmDriver; // Pointer to the PCA9685 PWM Driver
	// GPIO pins for x-direction Stepper
	exploringRPi::GPIO	x_Inverted_Enable;
	exploringRPi::GPIO				x_MS1;
	exploringRPi::GPIO				x_MS2;
	exploringRPi::GPIO				x_MS3;
	exploringRPi::GPIO	 x_Inverted_Reset;
	exploringRPi::GPIO	 x_Inverted_Sleep;
	exploringRPi::GPIO		  x_Direction; // Assuming Low is Forward. Verify by test

	// GPIO pins for Z-direction Stepper
	exploringRPi::GPIO	z_Inverted_Enable;
	exploringRPi::GPIO				z_MS1;
	exploringRPi::GPIO				z_MS2;
	exploringRPi::GPIO				z_MS3;
	exploringRPi::GPIO	 z_Inverted_Reset;
	exploringRPi::GPIO	 z_Inverted_Sleep;
	exploringRPi::GPIO		  z_Direction;

	const float x_dir_Map[3][6] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
	};

	const float x_offsets[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	
	const float z_dir_Map[3][6]{
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
	};

}; // end of Motor Class


