#include "Rook.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

Rook::Rook(bool white , bool motion, bool attack) : Piece(white, motion, attack){
	
}

bool Rook::move(int orow, int ocol, int nrow, int ncol)
{

	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();

	/*XOR used to ensure that the diffrow and diffcol are never equal tp ensure the rook's linear movement*/
	if (p == nullptr && (diffrow ^ diffcol)) //ToDo:check for adjacent squares
	{
		return true;
	}
	if (p->isWhite() == isWhite()) {
		return false;
	}
	return false;
}

