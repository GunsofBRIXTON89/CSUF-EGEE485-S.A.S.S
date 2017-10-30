// ============================================================================
// File: Storage_System.cpp
// Programmers: Jose Ordaz & James Chen
// Date: 12DEC17
// Class: EGEE-485 "Senior Design Laboratory" 
// Professor: Dr. Haung, Jidong
// Assignment: Self-resizing Automated Storage Sysyem (S.A.S.S)
// Description: Implementation for Storage_System Class
// ============================================================================
#include<stdexcept>
#include"Storage_System.h"

using namespace std;


// === DisplayContainer =========================================================
// 
// ============================================================================
void	Storage_System::DisplayContainer(int i, int j){
	std::cout << "=========\n " <<
		"|   " << SS_Array[i][j].Get_cState() << "   |\n" <<
		"=========" << end;
} // end of DisplayContainter



// === PrintCell ==============================================================
// 
// ============================================================================
void	Storage_System::PrintCellInfo(int i, int j, int k){
	SS_Array[i][j].print_cell_contents(k);
	
} // end of Print Cell



// === IsSpaceAvailable =======================================================
// 
//
//
// Input: N/A
//
// Output:
//		Returns true when there is a container that has an Open Cell.
//		Returns false if there no more space in the Storage System.
// ============================================================================
bool	Storage_System::IsSpaceAvailable(){
	for (int i = 0 ; i < MAX_CONTAINER_ROWS; ++i) {
		for (int j = 0; j < MAX_CONTAINER_COLS; ++j) {
			int cstate = SS_Array[i][j].Get_cState();
			if ((cstate == NONE_FILLED) || (cstate == SECOND_FILLED)) {
				// point open_Container to current Container
				open_Container = &SS_Array[i][j];
				//update open_CellNum to bottom cell
				open_CellNum = BOTTOM;
				return true;
			}else if (cstate == FIRST_FILLED) {
				// point open_Container to current Container
				open_Container = &SS_Array[i][j];
				//update open_CellNum to top cell
				open_CellNum = TOP;
				return true;
			}else {  //cstate == LARGE, Go to next iteration
			}

		} // j loop
	} // i loop

	return false;

} // end of IsSpaceAvialable



// === IsSpaceAvailable(int) ==================================================
// 
// Overloaded functions for when user wants to find specific
// container cases other than the first immediate cell. It compares 
// the input with the container states in the storage system and return true
// one first instance of equality; but not before updating the members
// "open_Cellnum" and "open_Container."
//
// Input:
//		specific_case [IN] -- an interger value (0 to 4 Inclusive) that 
//		represents a targeted container state
//
// Output:
//		true: specific case exist and  member Open_Container now points to it.
//		false: the specifica case does not exist in the system and Open_Container
//			   points to the previous containter it was pointing to.
//		
// ============================================================================
bool	Storage_System::IsSpaceAvailable(int specific_case) {
	for (int i = 0; i < MAX_CONTAINER_ROWS; ++i) {
		for (int j = 0; j < MAX_CONTAINER_COLS; ++j) {
			int cstate = SS_Array[i][j].Get_cState();
			if ( (cstate == specific_case) ){
				// point open_Container to current Container
				open_Container = &SS_Array[i][j];
				//update open_CellNum to bottom cell
				open_CellNum = BOTTOM;
				return true;
			}else {}
		} // j loop
	} // i loop

	return false;

} // end of IsSpaceAvailable(int)



// === Decrement_Avl_Cells ====================================================
// 
// Decrements private member available_cells. Throws Exception if
// attempting to decrement below zero.
//
// Input:
//
// Output:
//
// ============================================================================
void	Storage_System::Decrement_Avl_Cells(){
	if (available_Cells == 0){ 
		throw out_of_range("Out_of_range Error: Cannot Decrement Zero Cells");
	}
	--available_Cells;

} // end of Decrement_Avl_Cells




// === Increment_Avl_Cells ====================================================
//
// Increments private member available_cells. Throws Exception if 
// attempting to Increment past MAX_AVAILABLE_CELLS.
//
// ============================================================================
void	Storage_System::Increment_Avl_Cells() {
	if (available_Cells == MAX_AVAILABLE_CELLS) {
		throw out_of_range("Out_of_range Error: Cannot Increment past Max Cells")
	}
	++available_Cells;

} // end of Increment_Avl_Cells



// === Insert_Item ===========================================================
// 
// This function take in arguements call 
// 
// Notes: 
//		This function operates under the assumption that the user checked 
//		to see if there is space in the system to insert the item. If they
//		have done so, open_container will be pointing to the right location.
//		
//		Also, note there is no timestamp being passed. This is because the
//		timestamp is initiated when the Cell object is initiated
//		
// Input:
//		all arguements [IN] -- data that will be stored in the Cell
//		
// ============================================================================
void	Storage_System::Insert_Item(string name, string expiration, double height,
		 double dia_length, double volume, double labeled_oz,double approx_weight){
	
	// this function call updates the container state as well
	open_Container->Container::Insert_Item( open_cellNUM , name, expiration, height,
									  dia_length,volume, labeled_oz, approx_weight);
	Decrement_Avl_Cells();
	
} // End of Insert_Item(...)













/*	std::cout << std::string(10*3 + 2*3, '-') << "\n";
	for(i; i < MAX_CONTAINER_ROWS; ++i) {
			SS_Array[i][0]
			std::cout << prd(,0,10)       << " | "
				      << prd(x,0,10)     << " | "
					  << prd(,0,10) << "\n";
			std::cout << std::string(10 * 3 + 2 * 3, '-') << "\n";
		}
	}
	*/