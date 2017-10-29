// ============================================================================
// File: Cell.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation for Cell Class
// ============================================================================
#include "Cell.h"



// === Clear_Cell =============================================================
// Description:
// ============================================================================
void	Cell::Clear_Cell() {
	itemName.clear();
	itemName = "No name";
	itemExpiration.clear();
	itemExpiration = "No name";
	item_dia_length = 0.0;
	itemVolume = 0.0;
	item_Labeled_Oz = 0.0;
	item_approx_weight = 0.0; 
	itemTimestamp = NULL;
	SetFillStatus(false);
} // end of Clear_Cell