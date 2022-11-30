#pragma once
#include "Piece.h"
#include "Square.h"

class King : public Piece
{
public:
	King();
	King(bool white);
	bool move(int orow, int ocol, int nrow, int ncol);

private:/*
	SquarePtr NW;
	SquarePtr NE;
	SquarePtr SW;
	SquarePtr SE;
	SquarePtr north;
	SquarePtr south;
	SquarePtr east;
	SquarePtr west;*/

};