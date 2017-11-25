// ============================================================================
// File: Container.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation for Container Class
// ============================================================================
#include <cstring>
#include "Container.h"

// === Update_cState ==========================================================
// Description: 
// ============================================================================
void Container::Update_cState(){
	bool x = Storage_Cell[Bottom_cell].GetFillStatus(); 
	bool y = Storage_Cell[Top_cell].GetFillStatus(); 
	
	if (x && y) { // two possible cases: NONE_FILLED or LARGE
		if (x = true) {
			container_State = CLARGE;
			return;
		}else{
			container_State = NONE_FILLED;
			return;
		}
	}else if (x || y) { // two possible cases: FIRST_FILLED or SECOND_FILLED
		if (x = true) {
			container_State = FIRST_FILLED;
			return;
		}
		else {
			container_State = SECOND_FILLED;
			return;
		}
	}
	

} // end of Update_cState()



// Cell Wrappers

// === Get_ItemName ===========================================================
// 
// 
// Input:
//
// Output:
//
// ============================================================================
string		Container::Get_ItemName(int CellNum){
	return Storage_Cell[CellNum - 1].GetItemName(); 
} // end of Get_Item Name



// === Get_Expiration =========================================================
// 
//
// Input:
//
// Output:
//
// ============================================================================
string		Container::Get_Expiration(int CellNum){
	return Storage_Cell[CellNum - 1].GetExpiration();
} // end of Get_Expiration



// === Get_Timestamp ==========================================================
// 
//
// Input:
//
// Output:
//
// ============================================================================
time_t		Container::Get_Timestamp(int CellNum){
	return Storage_Cell[CellNum - 1].GetTimestamp();
} // end of Get_Timestamp



// === Set_ItemName  ==========================================================
// 
//
// Input:
//
// Output:
//
// ============================================================================
void		Container::Set_ItemName(string Name, int CellNum){
	Storage_Cell[CellNum - 1].SetItemName(Name);
} // end of Set_ItemName



// === Set_Expiration =========================================================
// 
//
// Input:
//
// Output:
//
// ============================================================================
void	Container::Set_Expiration(string  Name, int CellNum){
	Storage_Cell[CellNum - 1].SetExpiration(Name);
} // end of Set_Expiration



// === Set_FillStatus =========================================================
// 
//
// Input:
//
// ============================================================================
void	Container::Set_FillStatus(bool status, int CellNum){
	Storage_Cell[CellNum - 1].SetFillStatus(status);
} // end of Set_FillStatus



// === Clear_Cell =============================================================
//
//
//
// ============================================================================
void	Container::Clear_Cell(int CellNum){
	Storage_Cell[CellNum - 1].Clear_Cell();
} // end of Clear_Cell




// === Print_Cell_Contents ====================================================
//
//
//
// ============================================================================
void	Container::Print_Cell_Contents(int CellNum) {
	Storage_Cell[CellNum - 1].Print_Cell_Contents();
 
} // end of Print_Cell_Contents



// === Insert_Item ===========================================================
// 
// This function takes in arguements and dynamically allocates a cell that is
// initialized with those arguements.This function also updates the 
// container state.
//
// Notes: 
//		Also, note there is no timestamp being passed. This is because the
//		timestamp is initiated when the Cell object is initiated
//		
// Input:
//		all arguements [IN] -- data will be stored in the Cell
//		
// ============================================================================
void	Container::Insert_Item(int cell_Number, string name, string expiration, 
							   double height, double dia_length, double volume, 
										double labeled_oz, double approx_weight){

	Cell* myCell = new Cell(name, expiration, height, dia_length, volume,
		labeled_oz, approx_weight);
	Storage_Cell[cell_Number - 1] = *myCell;
	delete myCell;
	Update_cState();

	return;

} // End of Insert_Item(...)