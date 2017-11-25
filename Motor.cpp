// ============================================================================
// File: Motor.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation of Motor Class
// ============================================================================
#include<stdexcept>
#include "Motor.h"


Motor::Motor(exploringRPi::PWMDriver *pwmDriver) :
													pwmDriver(pwmDriver),
													x_OutputNumber(X_MOTOR),
													x_Inverted_Enable(GPIO13),
													x_MS1(GPIO19),
													x_MS2(GPIO26),
													x_MS3(GPIO14),
													x_Inverted_Sleep_And_Reset(GPIO15),
													//x_Inverted_Sleep(GPIO18),
													x_Direction(GPIO24),
													// Vertical Movement
													z_OutputNumber(Z_MOTOR),
													z_Inverted_Enable(GPIO17),
													z_MS1(GPIO27),
													z_MS2(GPIO22),
													z_MS3(GPIO10),
													z_Inverted_Sleep_And_Reset(GPIO9),
													//z_Inverted_Sleep(GPIO11),
													z_Direction(GPIO12) {
		// X Related
		x_Inverted_Enable.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Enable.setActiveLow();
		x_MS1.setDirection(exploringRPi::OUTPUT);
		x_MS2.setDirection(exploringRPi::OUTPUT);
		x_MS3.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Sleep_And_Reset.setDirection(exploringRPi::OUTPUT);
		x_Inverted_Sleep_And_Reset.setActiveLow();
		//x_Inverted_Sleep.setDirection(exploringRPi::OUTPUT);
		//x_Inverted_Sleep.setActiveLow();
		x_Direction.setDirection(exploringRPi::OUTPUT);
		x_Direction.setActiveLow();
		x_OutputNumber = X_MOTOR;
		screw_pitch[X] =  2.0f;
		Set_FullStep();

		// Z Related
		z_Inverted_Enable.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Enable.setActiveLow();
		z_MS1.setDirection(exploringRPi::OUTPUT);
		z_MS2.setDirection(exploringRPi::OUTPUT);
		z_MS3.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Sleep_And_Reset.setDirection(exploringRPi::OUTPUT);
		z_Inverted_Sleep_And_Reset.setActiveLow();
		//z_Inverted_Sleep.setDirection(exploringRPi::OUTPUT);
		//z_Inverted_Sleep.setActiveLow();
		z_Direction.setDirection(exploringRPi::OUTPUT);
		z_OutputNumber = Z_MOTOR;
		screw_pitch[Z] = 5.0f;
		Set_FullStep(Z);

		curr_Motor_dir = Forward;

		for (int i = 0; i < NUM_MOTORS; ++i){
			rpm[i] = 0.0f;
			dist[i] = 0.0f;
			frequency[i] = 2400.0f;
			velocity[i] = DEFAULT_VEL; 
			wait_time[i] = 10000;
			traveled[i] = 0.0f;
		}

} // end of  Motor Constructor


// === Validate_Key ===========================================================
//
// Everytime the Motor object wants to use the I2C line, it must first call on 
// this function to confirm it has exclusive access to the I2C line
//
// ============================================================================
//bool	Motor::Validate_Key() {
//	return( motor_key == motor_I2C->Get_Access_Key() );
//
//} // end of Validate_Key



// === Set_Dist_Travel ========================================================
//
//
//
// ============================================================================
void Motor::Set_Dist_Travel(int motor, const float dist) {
	float proposed_netDist = dist + traveled[motor];
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
	wait_time[motor] = static_cast<unsigned long>((dist / velocity[motor]) * 1000000);
	frequency[motor] = (velocity[motor]/screw_pitch[motor])*STEPS_PER_ROTATION;
	rpm[motor] = ((float)(velocity[motor] / screw_pitch[motor]))*60.0f;

} // end of Set_Dist_Travel



// === Set_Velocity ===========================================================
//
// Sets the Velocity for either X or Z axis Stepper motor in (mm/s)
//
// ============================================================================
void Motor::Set_Velocity(int velocity, int motor) {
	if((this->velocity[motor] < MIN_VEL)||(this->velocity[motor]>MAX_VEL)){
		throw out_of_range("Attempting to set Velocity out of bounds");
	}
	this->velocity[motor] = static_cast<float> (velocity);
} // end of Set_Velocity



// === Set_Direction ==========================================================
//
// Sets the direction for either the X or Z axis stepper motor by setting their
// respective Stepper driver pin to logic [HIGH] or [LOW].
//
// ============================================================================
void Motor::Set_Direction(int motor, int dir) {
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



// === Move_Motor =============================================================
//
//
// ============================================================================
void Motor::Move_Motor(float distance, int motor, int dir) {
	int motorPin;
	if (motor == Z) {
		motorPin = Z_MOTOR; 
	}else { motorPin = X_MOTOR; }
	if (dir != curr_Motor_dir) {
		Set_Direction(motor, dir);
	}
	Set_Dist_Travel(motor, distance);
	this->pwmDriver ->reset();
	this->pwmDriver->setFrequency(frequency[motor]);
	this->pwmDriver->setOutput(motorPin, STEPPER_DUTY_CYCLE);
	usleep(wait_time[motor]);
	this->pwmDriver->sleep();
	Update_CurrLocation(motor, dir, distance);
	

} // end of Move_Motor



// === Update_CurrLocation ===========================================================
//
//  Updates the current location of either the x or z axis depending on the inputs
//
// ===================================================================================
void Motor::Update_CurrLocation(int motor, int dir, float distance) {
	if ((dir == Reverse)) {
		if (motor == Z) {
			z_currLocation -= distance;
		}
		else { x_currLocation -= distance; }
	}
	else { // Direction is Forward
		if (motor == Z) {
			z_currLocation += distance;
		}
		else { x_currLocation += distance; }
	}

} // end of Update_CurrLocation



// === Set_FullStep ================================================================== 
//
//  Updates the current location of either the x or z axis depending on the inputs
//
// ===================================================================================
void Motor::Set_FullStep(int motor) {
	if (motor = Z) {
		z_MS1.setActiveLow();
		z_MS2.setActiveLow();
		z_MS3.setActiveLow();
	}else {
		x_MS1.setActiveLow();
		x_MS2.setActiveLow();
		x_MS3.setActiveLow();
	}
} // end of Set_FullStep


// === Return_Home =================================================================== 
//
//  
// ===================================================================================
void Motor::Return_Home(int motor, int direction) {
	float distance;
	if (motor == Z) {
		distance = z_currLocation;
	}
	else {
		distance = x_currLocation;
	}
	Move_Motor(distance, motor, direction);

} // end of Return_Home

  
  
// === Return_xHome ==================================================================
//
// 
// ===================================================================================
void Motor::Return_xHome(){
	Return_Home(X);
} // end of Return_xHome



// === Return_zHome ==================================================================
//
// 
// ===================================================================================
void Motor::Return_zHome() {
	Return_Home(Z);
} // end of Return_zHome



// === Set_zVelocity ==================================================================
//
// 
// ===================================================================================
void Motor::Set_zVelocity(int zVel) {
	Set_Velocity(zVel, Z);
} // end of Set_zVelocity



// === Set_zVelocity =================================================================
//
// 
// ===================================================================================
void Motor::Set_xVelocity(int xVel) {
	Set_Velocity(xVel, X);
} // end of Set_xVelocity



// === Move_zDirection ===============================================================
//
// 
// ===================================================================================
void Motor::Move_zDirection(float distance){
	int direction;
	if (distance < 0.0) {
		direction = Reverse;
		distance = abs(distance);
	}
	else {
		direction = Forward;
	}
	Move_Motor(distance,Z, direction);

} // end of Move_zDirection



// === Move_xDirection ===============================================================
//
// 
// ===================================================================================
void Motor::Move_xDirection(float distance) {
	int direction;
	if (distance < 0.0) {
		direction = Reverse;
		distance = abs(distance);
	}
	else { 
		direction = Forward;
	}
	Move_Motor(distance, X, direction);

} // end of Move_xDirection


// === Move__To_Row ==================================================================
//
// 
// ===================================================================================
void Motor::Move_To_Row(int row, int col,int t_or_b) {
	if ((col < 0) || (col > 3)) {
		throw out_of_range("Column must be within Range");
	}else if ((row < 0) || (row > 3)) {
		throw out_of_range("Row must be withing Range");
	}

	float current_ZDist = z_currLocation; // Current distance from the Origin
	float want_ZDist;
	if (t_or_b == Top) { 
		want_ZDist = z_dir_Map[row + 1][col];
	}else {
		want_ZDist = z_dir_Map[row][col]; // Distance from origin that we want to be at
	}

	want_ZDist = z_dir_Map[row][col]; // Distance from origin that we want to be at
	float delta_Dist = want_ZDist - current_ZDist; // Distance in Difference
    // delta_Dist Could be (+) or (-) next function call handles this
	Move_zDirection(delta_Dist);

} // end of Move_To_Row



// === Move__To_ Col =================================================================
//
// 
// ===================================================================================
void Motor::Move_To_Col(int row,int col) {
	if ((col < 0) || (col > 3)) {
		throw out_of_range("Column must be within Range");
	}else if ((row < 0) || (row > 3)) {
		throw out_of_range("Row must be withing Range");
	}
	float current_XDist = x_currLocation; // Current distance from the Origin
	float want_XDist = x_dir_Map[row][col]; // Distance from origin that we want to be at
	float delta_Dist = want_XDist - current_XDist; // Distance in Difference
    // delta_Dist Could be (+) or (-) next function call handles this
	Move_xDirection(delta_Dist);

} // end of Move_To_Col



// === Move__To_Cordinates ===========================================================
//
// 
// ===================================================================================
void Motor::Move_To_Cordinates(int row, int col,int t_or_b) {
	if (row == 0) {
		Return_zHome();
	}else if (col) {
		Return_xHome();
	}else {
		Move_To_Col(row, col);
		if (t_or_b == Top){
			Move_To_Row(row, col);
		}else {

		}
	}
} // end of Move_To_Cordinates