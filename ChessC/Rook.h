#pragma once
#include "Piece.h"
#include "Square.h"

class Rook : public Piece
{
public:
	Rook(bool white);
	void move(int row, int column);

private:
	SquarePtr north;
	SquarePtr south;
	SquarePtr east;
	SquarePtr west;


};