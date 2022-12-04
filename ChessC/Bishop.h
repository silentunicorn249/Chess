#pragma once
#include "Piece.h"
#include "Square.h"
#include <vector>

class Bishop : public Piece
{
public:
	char getName();
	Bishop();
	Bishop(bool white, bool motion, bool attack);
	bool move(int orow, int ocol, int nrow, int ncol);

	void getAllMoves(int row, int col);
	vector<Square*> getVec();


private:
	vector<Square*> avMoves;


};

