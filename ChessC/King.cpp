#include "King.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

King::King(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool King::move(int orow, int ocol, int nrow, int ncol)
{
	Square* s = b.board[nrow][ncol];
	Piece* p = s->piece;
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	/*King is only allowed one move*/
	if (diffrow > 1 || diffcol > 1)
	{
		return false;
	}
	/*equal 2 -->diagonal move*/
	/*equal one --> linear move in either direction*/
	if (p==nullptr && (diffrow + diffcol) <= 2)
		return true;
	if (p->isWhite() == isWhite()) {
		return false;
	}
	return false;
}

