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
	bool x = Storage_Cell[0].GetFillStatus; // Check Bottom Cell
	bool y = Storage_Cell[1].GetFillStatus; // Check Top Cell
	
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
// Description: 
// ============================================================================
string	Container::Get_ItemName(int CellNum){
	return Storage_Cell[CellNum - 1].GetItemName(); 
} // end of Get_Item Name



// === Get_Expiration =========================================================
// Description: 
// ============================================================================
string	Container::Get_Expiration(int CellNum){
	return Storage_Cell[CellNum - 1].GetExpiration();
} // end of Get_Expiration



// === Get_Timestamp ==========================================================
// Description: 
// ============================================================================
time_t	Container::Get_Timestamp(int CellNum){
	return Storage_Cell[CellNum - 1].GetTimestamp();
} // end of Get_Timestamp



// === Set_ItemName  ==========================================================
// Description: 
// ============================================================================
void	Container::Set_ItemName(string Name, int CellNum){
	Storage_Cell[CellNum - 1].SetItemName(Name);
} // end of Set_ItemName



// === Set_Expiration =========================================================
// Description: 
// ============================================================================
void	Container::Set_Expiration(string  Name, int CellNum){
	Storage_Cell[CellNum - 1].SetExpiration(Name);
} // end of Set_Expiration



// === Set_FillStatus =========================================================
// Description: 
// ============================================================================
void	Container::Set_FillStatus(bool status, int CellNum){
	Storage_Cell[CellNum - 1].SetFillStatus(status);
} // end of Set_FillStatus



// === Clear_Cell =============================================================
// Description: 
// ============================================================================

void	Container::Clear_Cell(int CellNum){
	Storage_Cell[CellNum - 1].Clear_Cell();
} // end of Clear_Cell
