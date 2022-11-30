#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include "Square.h"
#include "gBoard.h"

using namespace std;

Pawn::Pawn(bool white) : Piece(white) {

}

bool Pawn::move(int orow, int ocol, int nrow, int ncol)
{
	Square* s = b.board[nrow][ncol];
	Piece* p = s->piece;

	if (p == nullptr)
		return true;
	if (p->isWhite() == isWhite()) {
		return false;
	}

}
