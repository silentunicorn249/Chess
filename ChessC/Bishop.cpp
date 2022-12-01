#include "Bishop.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

Bishop::Bishop(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Bishop::move(int orow, int ocol, int nrow, int ncol)
{
	return true;
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();

	if (p == nullptr && (diffrow == diffcol)) //ToDo:check for adjacent squares
	{
		return true;
	}
	if (p->isWhite() == isWhite()) {
		return false;
	}
	/*else is attack*/
	return false;
}

