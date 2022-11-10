#pragma once
#include "Piece.h"
#include "Square.h"

class King : Piece
{
public:
	void move(int row, int column);

private:
	SquarePtr NW;
	SquarePtr NE;
	SquarePtr SW;
	SquarePtr SE;
	SquarePtr north;
	SquarePtr south;
	SquarePtr east;
	SquarePtr west;

};