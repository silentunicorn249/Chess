#pragma once
#include "Piece.h"
#include "Square.h"


class Pawn : public Piece
{
public:
	Pawn(bool white);
	bool move(int orow, int ocol, int nrow, int ncol);


private:
	/*SquarePtr up;
	SquarePtr upLeft;
	SquarePtr upRight;*/

};

