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

Motor::Motor(exploringRPi::PWMDriver *pwmDriver) :
													pwmDriver(pwmDriver),
													x_OutputNumber(X_MOTOR),
													x_Inverted_Enable(GPIO13),
													x_MS1(GPIO19),
													x_MS2(GPIO26),
													x_MS3(GPIO14),
													x_Inverted_Reset(GPIO15),
													x_Inverted_Sleep(GPIO18),
													x_Direction(GPIO24),
													// Vertical Movement
													z_OutputNumber(Z_MOTOR),
													z_Inverted_Enable(GPIO17),
													z_MS1(GPIO27),
													z_MS2(GPIO22),
													z_MS3(GPIO10),
													z_Inverted_Reset(GPIO9),
													z_Inverted_Sleep(GPIO11),
													z_Direction(GPIO12) {
		x_Inverted_Enable.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Enable.setActiveLow();
		x_MS1.setDirection(exploringRPi::OUTPUT);
		x_MS1.setActiveLow();
		x_MS2.setDirection(exploringRPi::OUTPUT);
		x_MS2.setActiveLow();
		x_MS3.setDirection(exploringRPi::OUTPUT);
		x_MS3.setActiveLow();
		x_Inverted_Reset.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Reset.setActiveLow();
		x_Inverted_Sleep.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Sleep.setActiveLow();
		x_Step.setDirection(exploringRPi::OUTPUT);
		x_Step.setActiveLow();
		x_Direction.setDirection(exploringRPi::OUTPUT);
		x_Direction.setActiveLow();
		z_Inverted_Enable.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Enable.setActiveLow();
		z_MS1.setDirection(exploringRPi::OUTPUT);
		z_MS1.setActiveLow();
		z_MS2.setDirection(exploringRPi::OUTPUT);
		z_MS2.setActiveLow();
		z_MS3.setDirection(exploringRPi::OUTPUT);
		z_MS3.setActiveLow();
		z_Inverted_Reset.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Reset.setActiveLow();
		z_Inverted_Sleep.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Sleep.setActiveLow();
		z_Direction.setDirection(exploringRPi::OUTPUT);
		int		x_OutputNumber = X_MOTOR;
		int		z_OutputNumber = Z_MOTOR;
		const float   pwm_DutyCycle = STEPPER_DUTY_CYCLE;
		screw_pitch[X] = 2.0;
		screw_pitch[Z] = 5.0;
		curr_Motor_dir = Forward;

		for (int i; i < NUM_MOTORS);++i){
			float	rpm[i] = 0.0;
			int		dist[i] = 0.0;
			float	frequency[i] = 2400.0;
			float   velocity[i] = DEFAULT_VEL; 
			unsigned long int wait_time[NUM_MOTORS] = 10000;
			float traveled[i] = 0.0;

	}
} // end of  Motor Constructor







// === Validate_Key ===========================================================
//
// Everytime the Motor object wants to use the I2C line, it must first call on 
// this function to confirm it has exclusive access to the I2C line
//
// ============================================================================
bool	Motor::Validate_Key() {
	return( motor_key == motor_I2C->Get_Access_Key() );

} // end of Validate_Key



// === Set_Dist_Travel ========================================================
//
//
//
// ============================================================================
void Motor::Set_Dist_Travel(int motor, const float dist) {
	int proposed_netDist = dist + traveled[motor];
	if (motor == Z) {
		if ((dist < MIN_DIST_TRAVELED) || (proposed_netDist > MAX_Z_DIST_TRAVELED)) {
			throw out_of_range("Attempting to move Z out of range");
		}
	}else {
		if ((dist < MIN_DIST_TRAVELED) || (proposed_netDist > MAX_X_DIST_TRAVELED)) {
			throw out_of_range("Attempting to move X out of range");
		}
	}
	this->dist[motor] = dist;
	wait_time[motor] = (float)(dist / velocity[motor]) * 1000000;
	frequency[motor] = (velocity[motor]/screw_pitch[motor])*STEPS_PER_ROTATION;
	rpm[motor] = ((float)(velocity[motor] / screw_pitch[motor]))*60.0;
} // end of Set_Dist_Travel


// === Set_Velocity ===========================================================
//
// Sets the Velocity for either X or Z axis Stepper motor in (mm/s)
//
// ============================================================================
void Motor::Set_Velocity(const int velocity, int motor) {
	if((this->velocity[motor] < MIN_VEL)||(this->velocity[motor]>MAX_VEL)){
		throw out_of_range("Attempting to set Velocity out of bounds");
	}
	this->velocity[motor] = velocity;
} // end of Set_Velocity



// === Set_Direction ===========================================================
//
// Sets the direction for either the X or Z axis stepper motor by setting their
// respective Stepper driver pin to logic [HIGH] or [LOW].
//
// ============================================================================
void Motor::Set_Direction(int motor = X, int dir = Forward) {
	if (motor == Z) {
		if (dir == Reverse) {
			z_Direction.setActiveHigh();
		}
		z_Direction.setActiveLow();
	}
	else {
		if (dir == Reverse) {
			x_Direction.setActiveHigh();
		}
		x_Direction.setActiveLow();
	}
} // end of Set_Direction



// === Move_Motor ===========================================================
//
//
// ============================================================================
void Motor::Move_Motor(float distance, int motor, int dir) {
	int motorPin;
	if (motor == Z) {
		motorPin = Z_MOTOR; 
	}else { motorPin = X_MOTOR; }
	if (dir != curr_Motor_dir) {
		Set_Direction(motor,dir);
		Set_Dist_Travel(motor, distance);
		this->pwmDriver ->reset();
		this->pwmDriver->setFrequency(frequency[motor]);
		this->pwmDriver->setOutput(motorPin, STEPPER_DUTY_CYCLE);
		usleep(wait_time[motor]);
		this->pwmDriver->sleep();
	}

	

} // end of Move_Motor
