// ============================================================================
// File: Container.h
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Header file for Container Class
// ============================================================================
#include"Cell.h"
using namespace std;

#define MAX_CELLS 2



#pragma once // designed to cause the current source file to be included once
//  for compilation

enum cState{ NONE_FILLED, FIRST_FILLED, SECOND_FILLED, BOTH_FILLED, CLARGE};
enum container_cell{ Bottom_cell , Top_cell };

class Container{
public:
	// Default Ctor
	Container() : shelf_State(true), container_State(NONE_FILLED) {} 

	
	// Accessors 
	int		Get_cState() { return container_State; }
	bool	IsShelf() { return shelf_State; }
	string	Get_ItemName(int CellNum);
	string	Get_Expiration(int CellNum);
	time_t	Get_Timestamp(int CellNum);
	void	Print_Cell_Contents(int CellNum);
	
	
	// Mutators
	void	Set_ShelfState(bool state) { shelf_State = state; }
	void	Update_cState();
	void	Set_ItemName(string Name, int CellNum); 
	void	Set_Expiration(string  Name, int CellNum);
	void	Set_FillStatus(bool status, int CellNum);
	void	Clear_Cell(int CellNum);
	void	Insert_Item(int cell_Number,string name, string expiration,
						double height, double dia_length, double volume,
								double labeled_oz, double approx_weight);



private:
	Cell	Storage_Cell[MAX_CELLS];
	int		container_State;
	bool	shelf_State; //default true

}; // end of Container Class