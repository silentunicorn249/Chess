#include "Queen.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

Queen::Queen(bool white,bool motion, bool attack) : Piece(white, motion, attack){

}

bool Queen::move(int orow, int ocol, int nrow, int ncol)
{
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();

	if (p == nullptr && ((diffrow == diffcol) || (diffrow ^ diffcol))) //ToDo:check for adjacent squares
	{
		return true;
	}

	if (p->isWhite() == isWhite()) {
		return false;
	}
	return false;
}

