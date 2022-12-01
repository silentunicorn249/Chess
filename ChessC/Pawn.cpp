#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include "Square.h"
#include "gBoard.h"

using namespace std;

Pawn::Pawn(bool white,bool motion, bool attack) : Piece(white,motion,attack) {

}

bool Pawn::move(int orow, int ocol, int nrow, int ncol)
{

	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();
	if (ocol != ncol && !isAttack()) //bool isAttack
	{
		return false;
	}
	/*check for square availability to be moved to*/
	/*Black is the one playing at the top so its moves is estimated through addition unlike the "White"*/
	if (p == nullptr && !isWhite()) //for black
	{
		/*first move check */
		if (nrow <= (orow + 2) && !isMoved() || (nrow == (orow+1) && isMoved())) //bool ismoved
		{
			return true;
		}

		return false;
	}

	if (p == nullptr && isWhite()) //for white
	{
		if (nrow <= (orow - 2) && !isMoved() || (nrow == (orow + 1) && isMoved())) //bool ismoved
		{
			return true;
		}

		return false;
	}
	if (p->isWhite() == isWhite()) {
		return false;
	}
}
