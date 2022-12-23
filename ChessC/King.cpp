#include "King.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char King::getName()
{
	return 'K';
}

King::King(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool King::move(int orow, int ocol, int nrow, int ncol)
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
	/*Square* s = b.board[nrow][ncol];
	Piece* p = s->piece;
	int diffrow = abs(nrow - orow);
	int diffcol = abs(ncol - ocol);
	if (diffrow > 1 || diffcol > 1)
	{
		return false;
	}
	/*equal 2 -->diagonal move*/
	/*equal one --> linear move in either direction*/
	/*if (!(p == nullptr)) {
		if (p->isWhite() == isWhite()) {
			return false;
		}
	}
	if ( (diffrow + diffcol) <= 2)
		return true;

	return false;*/
}

void King::getAllMoves(int row, int col)
{
	avMoves.clear();
	Square* s = b.board[row][col];
	Piece* p = s->piece;
	/*north*/
	if (row + 1 < 8)
	{
		s = b.board[row + 1][col];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (row - 1 >= 0)
	{
		s = b.board[row - 1][col];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col + 1 < 8)
	{
		s = b.board[row][col + 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col - 1 >= 0)
	{
		s = b.board[row][col - 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col + 1 < 8 && row + 1 < 8)
	{
		s = b.board[row + 1][col + 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col - 1 >= 0 && row + 1 < 8)
	{
		s = b.board[row + 1][col - 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col + 1 < 8 && row - 1 >= 0)
	{
		s = b.board[row - 1][col + 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}
	if (col - 1 >= 0 && row - 1 >= 0)
	{
		s = b.board[row - 1][col - 1];
		if (!(s->getPiece()))
		{
			avMoves.push_back(s);
		}
		else if ((s->getPiece() && p->isWhite() != s->getPiece()->isWhite()))
		{
			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);

		}
	}

}

vector<Square*> King::getVec()
{
	return avMoves;
}

void King::setVec(Board& bTest, vector<Square*>& moves)
{
	for (int i = 0; i < moves.size(); i++) {

		int row = moves[i]->getRow();
		int col = moves[i]->getCol();

		avMoves.push_back(bTest.board[row][col]);
	}
}