#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include "Square.h"
#include "gBoard.h"

using namespace std;

char Pawn::getName()
{
	return 'P';
}

Pawn::Pawn(bool white,bool motion,bool attack) : Piece(white,motion, attack) {

}

bool Pawn::move(int orow, int ocol, int nrow, int ncol)
{

	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();
	int diffcol = abs(orow-nrow);
	int diffrow = nrow-orow;
	if ((diffrow>0 && isWhite()) || (diffrow < 0 && !isWhite())) //bool isAttack
	{
		return false;
	}
	diffrow = abs(diffrow);
	/*check for square availability to be moved to*/
	if (p == nullptr) 
	{
		/*first move check*/
		if ((diffrow<=2 && !isMoved()) || (diffrow==1 && isMoved())) //bool ismoved
		{
			return true;
		}
		return false;
	}
	if (p->isWhite() == isWhite()) {
		return false;
	}
	else if (diffrow == 1 && diffcol == 1 && p->isWhite() != isWhite())
	{
		return true;
	}
}

