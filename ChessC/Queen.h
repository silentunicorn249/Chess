#pragma once
#include "Piece.h"
#include "Square.h"
#include <vector>


class Queen : public Piece
{
public:
	char getName();
	Queen(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);
	void getAllMoves(int row, int col);
	vector<Square*> getVec();
	void setVec(vector<Square*>& moves);
	vector<Square*> avMoves;

private:

};

