// ============================================================================
// File: Storage_System.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for Storage_System Class.
// ============================================================================
#include"Container.h"
using namespace std;

#define MAX_CONTAINER_ROW 3
#define MAX_CONTAINER_COL 3
#define MAX_AVAILABLE_CELLS 18

#pragma once // designed to cause the current source file to be included once
//  for compilation

enum 

class Storage_System:public {
public:
	Storage_System() : available_Cells(MAX_AVAILABLE_CELLS),  //Default Ctor
		open_Container->SS_Array[0][0], open_CellNum(1); {}
	// Accessors
	int Get_Avl_Cell() { return available_Cells; }

	// Mutators
	bool	IsSpaceAvailable();
	bool	IsSpaceAvailable(int specific_case);
	void	Decrement_Avl_Cells();
	void	Increment_Avl_Cells();
private:
	Container	SS_Array[MAX_CONTAINER_ROW][MAX_CONTAINER_COL];
	Container*									open_Container;
	int											  open_CellNum; 
	int										   available_Cells;
	
}; // end of Storage_System Class