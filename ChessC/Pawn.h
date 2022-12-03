#pragma once
#include "Piece.h"
#include "Square.h"


class Pawn : public Piece
{
public:
	char getName();
	Pawn(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);
	void getAllMoves(int row, int col);

private:
	/*SquarePtr up;
	SquarePtr upLeft;
	SquarePtr upRight;*/
	vector <Square*> avMoves;
};

