#pragma once
#include "Piece.h"
#include "Square.h"
#include <vector>


class King : public Piece
{
public:
	char getName();
	King();
	King(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);
	void getAllMoves(int row, int col);
	vector<Square*> getVec();
	void setVec(Board& bTest, vector<Square*>& moves);
	vector<Square*> avMoves;
private:
};