#pragma once
#include "Piece.h"
#include "Square.h"


class Pawn : Piece
{
public:
	void move(int row, int column);

private:
	SquarePtr up;
	SquarePtr upLeft;
	SquarePtr upRight;

};

