// ============================================================================
// File: Cell.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for Cell Class
// ============================================================================
#include<string>
#include <time.h>
using namespace std;

#pragma once // designed to cause the current source file to be included once
//  for compilation


class Cell{
public:

	// === Cell() =================================================================
	// Description: Default Cell constructor
	// ============================================================================
	Cell() : itemName("No name"), itemExpiration("No name"), itemTimestamp(NULL),
			 itemHeight(0.0), item_dia_length(0.0), itemVolume(0.0),
		     item_Labeled_Oz(0.0), item_approx_weight(0.0), fill_status(false) {
			} // end of Cell()



	// === Cell(string, string ...) ===============================================
	// Description: Parameterized Cell Constructor. Note that The member
	// item_Timestamp isn't initialzed via arguement, instead is initialized via 
	// a function call to gmtime()
	// ============================================================================
	Cell(string Name, string Expiration, double Height, double dia_length,
		           double Volume, double Labeled_Oz, double approx_weight){
		itemName = Name;
		itemExpiration = Expiration;
		item_dia_length = dia_length;
		itemVolume = Volume;
		item_Labeled_Oz = Labeled_Oz;
		item_approx_weight = approx_weight;
		// TODO: get the right function call to 
		time(&itemTimestamp); // raw time
		SetFillStatus(true);

	} // end of Cell(string, string ....)


	// Accessors
	string	GetItemName() { return itemName; }
	string	GetExpiration() { return itemExpiration; }
	bool	GetFillStatus(){ return fill_status; }
	time_t	GetTimestamp() { return itemTimestamp; }
	void	Print_Cell_Contents();


	// Mutatators
	void	SetItemName(string Name) { itemName = Name; }
	void	SetExpiration(string Expiration) { itemExpiration = Expiration; }
	void	SetFillStatus(bool status) { fill_status = status; }
	void	Clear_Cell(); 



private:
	string	itemName;
	string	itemExpiration;
	time_t	itemTimestamp;
	double	itemHeight; // in cm
	double	item_dia_length; // in cm
	double	itemVolume; // in (cm)^3
	double	item_Labeled_Oz; // in US Ounces
	double	item_approx_weight; // Using (Density of Water * Volume * G) + average Can/Jar weight.
	bool	fill_status;
}; // end of Cell Class