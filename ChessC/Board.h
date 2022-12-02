#pragma once
#include "Tree.h"
#include "Piece.h"
#include "Square.h"

class Board
{
public:
	Board(); 
	Square* board[8][8];
	void display();
private:


};



