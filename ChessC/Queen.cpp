#include "Queen.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char Queen::getName()
{
	return 'Q';
}

Queen::Queen(bool white,bool motion, bool attack) : Piece(white, motion, attack){

}

bool Queen::move(int orow, int ocol, int nrow, int ncol)
{
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	int temp;
	Square* ptr;
	Square* s = b.board[nrow][ncol];
	Piece* p = s->getPiece();

	if (!(p == nullptr)) {
		if (p->isWhite() == isWhite()) {
			return false;
		}
	}

	if (diffrow == diffcol)
	{
		//ta7t yemin
		if (ncol > ocol && nrow > orow) {
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
		if (ncol < ocol&& nrow < orow) {
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

	if (!(diffrow > 0 && diffcol > 0) ||
		!(diffrow == 0 && diffcol == 0)) //ToDo:check for adjacent squares
	{
		if (diffcol)
		{
			if (ncol < ocol)
			{
				temp = ncol;
				ncol = ocol;
				ocol = temp;
			}
			for (int i = ocol + 1; i < ncol; i++) {
				ptr = b.board[orow][i];
				if (ptr->getPiece()) {
					return false;
				}
			}
		}
		if (diffrow) {
			if (nrow < orow)
			{
				temp = nrow;
				nrow = orow;
				orow = temp;
			}
			for (int i = orow + 1; i < nrow; i++) {
				ptr = b.board[i][ocol];
				if (ptr->getPiece()) {
					return false;
				}
			}
		}

		return true;
	}
	return false;

}
