#include "Knight.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

Knight::Knight(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Knight::move(int orow, int ocol, int nrow, int ncol)
{

	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->piece;

	/*L-shaped move that requires 3 moves and no adjacent checks needed here since it jumpps*/
	if (p == nullptr && (diffrow + diffcol == 3) && (diffrow != 0) && (diffcol != 0))
	{
		return true;
	}

	if (p->isWhite() == isWhite()) {
		return false;
	}
	/*else is attack*/
	return false;
}

