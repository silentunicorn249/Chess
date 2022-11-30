#pragma once
#include "Piece.h"
#include "Square.h"

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(bool white);
	bool move(int orow, int ocol, int nrow, int ncol);

private:/*
	SquarePtr NW;
	SquarePtr NE;
	SquarePtr SW;
	SquarePtr SE;*/

};

