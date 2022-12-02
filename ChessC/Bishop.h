#pragma once
#include "Piece.h"
#include "Square.h"

class Bishop : public Piece
{
public:
	char getName();
	Bishop();
	Bishop(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);

private:/*
	SquarePtr NW;
	SquarePtr NE;
	SquarePtr SW;
	SquarePtr SE;*/

};

