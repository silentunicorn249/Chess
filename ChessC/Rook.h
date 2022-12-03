#pragma once
#include "Piece.h"
#include "Square.h"
#include <vector>
class Rook : public Piece
{
public:
	char getName();
	Rook();
	Rook(bool white , bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);
	void getAllMoves(int row, int col);

private:/*
	SquarePtr north;
	SquarePtr south;
	SquarePtr east;
	SquarePtr west;*/
	vector <Square*> avMoves;

};