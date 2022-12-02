#include "Knight.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char Knight::getName()
{
	return 'N';
}

Knight::Knight(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Knight::move(int orow, int ocol, int nrow, int ncol)
{

	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->piece;

	if (!(p == nullptr)) {
		if (p->isWhite() == isWhite()) {
			return false;
		}
	}

	/*L-shaped move that requires 3 moves and no adjacent checks needed here since it jumpps*/
	if ((diffrow + diffcol == 3) && (diffrow != 0) && (diffcol != 0))
	{
		return true;
	}

	/*else is attack*/
	return false;
}

