// ============================================================================
// File: Container.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation for Container Class
// ============================================================================

#include "Container.h"

// === Update_cState ==========================================================
// Description: 
// ============================================================================
void Container::Update_cState(){
	bool x = Storage_Cell[Bottom_cell].GetFillStatus; 
	bool y = Storage_Cell[Top_cell].GetFillStatus; 
	
	if (x && y) { // two possible cases: NONE_FILLED or LARGE
		if (x = true) {
			container_State = LARGE;
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




// === Print_cell_contents ====================================================
//
//
//
// ============================================================================
void	Container::print_cell_contents(int CellNum) {
	Storage_Cell[CellNum - 1].Print_Cell_Contents();
 
} // end of print_cell_contents