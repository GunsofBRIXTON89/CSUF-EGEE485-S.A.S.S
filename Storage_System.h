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

#define MAX_CONTAINER_ROWS 3
#define MAX_CONTAINER_COLS 3
#define MAX_AVAILABLE_CELLS 18

#pragma once // designed to cause the current source file to be included once
//  for compilation

enum cell{BOTTOM = 1, TOP};
enum item_size{SMALL, LARGE};  // SMALL represents the case of 1 Unit Cell
							   // LARGE = 1 Container to store

class Storage_System:public {
public:
	//Default Ctor
	Storage_System() : available_Cells(MAX_AVAILABLE_CELLS),  
		open_Container->SS_Array[0][0], open_CellNum(BOTTOM); {}

	// Accessors
	int Get_Avl_NumCells() { return available_Cells; }
	void DisplayContainer(int i, int j);
	void PrintCellInfo(int i, int j, int k);

	// Mutators
	void	Set_OpenCellNum(int cell_number) { open_CellNum = cell_number; }
	bool	IsSpaceAvailable();
	bool	IsSpaceAvailable(int specific_case);
	void	Decrement_Avl_Cells();
	void	Increment_Avl_Cells();
	void	Remove_Item(int i, int j, int k); //TODO
	void	FindItem(string item_name); //TODO?
	void	Insert_Item(string name, string expiration, double height, 
						double dia_length, double volume, double labeled_oz,
														double approx_weight); //TODO


private:
	Container	SS_Array[MAX_CONTAINER_ROWS][MAX_CONTAINER_COLS];
	Container*									open_Container;
	int											  open_CellNum; 
	int										   available_Cells;
	
}; // end of Storage_System Class