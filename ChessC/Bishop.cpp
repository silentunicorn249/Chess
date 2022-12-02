#include "Bishop.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char Bishop::getName()
{
	return 'B';
}

Bishop::Bishop(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Bishop::move(int orow, int ocol, int nrow, int ncol)
{
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();
	Square* ptr;
	
	if (!(p == nullptr)) {
		if (p->isWhite() == isWhite()) {
			return false;
		}
	}

	if (diffrow == diffcol)
	{
		//ta7t yemin
		if ( ncol > ocol && nrow > orow ) {
			// kona momken ne3mel orow + i
			for (int i = orow + 1, j = ocol + 1; i < nrow, j < ncol; i++, j++) {
				ptr = b.board[i][j];
				if (ptr->getPiece())
					return false;
			}
		}
		//fo2 yemin
		if (ncol > ocol && nrow < orow) {
			for (int i = orow - 1, j = ocol + 1; i > nrow, j < ncol; i--, j++) {
				ptr = b.board[i][j];
				if (ptr->getPiece())
					return false;
			}
		}
		//fo2 shemal
		if (ncol < ocol && nrow < orow) {
			for (int i = orow - 1, j = ocol - 1; i > nrow, j > ncol; i--, j--) {
				ptr = b.board[i][j];
				if (ptr->getPiece())
					return false;
			}
		}
		//ta7t shemal
		if (ncol < ocol && nrow > orow) {
			for (int i = orow + 1, j = ocol - 1; i < nrow, j > ncol; i++, j--) {
				ptr = b.board[i][j];
				if (ptr->getPiece())
					return false;
			}
		}
		return true;
	}

	return false;
}

