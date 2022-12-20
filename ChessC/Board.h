#pragma once

#include "Piece.h"
#include "Square.h"

class Board
{
public:
	Board();
	Board(const Board& oBoard);
	Square* board[8][8];
	void display();
private:


};



