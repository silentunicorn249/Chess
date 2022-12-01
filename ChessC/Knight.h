#pragma once
#include "Piece.h"
#include "Square.h"

class Knight : public Piece
{
public:
	Knight();
	Knight(bool white,bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);

private:/*
	SquarePtr UUR;
	SquarePtr UUL;
	SquarePtr UL;
	SquarePtr UR;
	SquarePtr DDR;
	SquarePtr DDL;
	SquarePtr DL;
	SquarePtr DR;*/

};