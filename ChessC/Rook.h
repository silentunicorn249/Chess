#pragma once
#include "Piece.h"
#include "Square.h"

class Rook : public Piece
{
public:
	Rook();
	Rook(bool white , bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);

private:/*
	SquarePtr north;
	SquarePtr south;
	SquarePtr east;
	SquarePtr west;*/


};