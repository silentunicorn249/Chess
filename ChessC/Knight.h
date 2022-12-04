
#pragma once
#include "Piece.h"
#include "Square.h"
#include <vector>

class Knight : public Piece
{
public:
	char getName();
	Knight();
	Knight(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);
	void getAllMoves(int row, int col);
	vector<Square*> getVec();

private:
	vector<Square*> avMoves;
};