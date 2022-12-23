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
	getAllMoves(orow, ocol);
	//	cout << endl << avMoves.size() << endl << endl;

	Square* ptr;
	/*check if any of the available moves corresponds the new value*/
	for (int i = 0; i < avMoves.size(); i++) {
		ptr = avMoves[i];
		if (ptr->getCol() == ncol && ptr->getRow() == nrow) {
			return true;
		}
	}return false;
	/*int diffrow = abs(nrow - orow);
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

	return false;*/
}

void Bishop::getAllMoves(int row, int col)
{
	avMoves.clear();
	Square* s = b.board[row][col];
	Piece* p = s->getPiece();
	Square* ptr;/*iterator*/
	/*SE*/
	for (int i = 1; row + i < 8 && col + i < 8; i++)
	{
		ptr = b.board[row + i][col + i];
		if (!(ptr->getPiece()))
			avMoves.push_back(ptr);
		else {
			if (isWhite() != ptr->getPiece()->isWhite())
			{
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);

			}break;

		}
	}
	/*NE*/
	for (int i = 1; col + i < 8 && row - i >= 0; i++)
	{
		ptr = b.board[row - i][col + i];
		if (!(ptr->getPiece()))
		{
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite())
			{
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);

			}break;

		}

	}
	/*SW*/
	for (int i = 1; row + i < 8 && col - i >= 0; i++)
	{
		ptr = b.board[row + i][col - i];
		if (!(ptr->getPiece()))
			avMoves.push_back(ptr);
		else {
			if (isWhite() != ptr->getPiece()->isWhite())
			{
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);

			}break;

		}
	}
	/*NW*/
	for (int i = 1; row - i >= 0 && col - i >= 0; i++)
	{
		ptr = b.board[row - i][col - i];
		if (!(ptr->getPiece()))
			avMoves.push_back(ptr);
		else {
			if (isWhite() != ptr->getPiece()->isWhite())
			{
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);

			}break;

		}
	}
}

vector<Square*> Bishop::getVec()
{
	return avMoves;
}

void Bishop::setVec(vector<Square*>& moves)
{
	avMoves = moves;
}

