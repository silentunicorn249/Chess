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
	getAllMoves(orow, ocol);

	Square* ptr;
	for (int i = 0; i < avMoves.size(); i++) {
		ptr = avMoves[i];
		if ((ptr->getCol() == ncol) && ptr->getRow() == nrow) {
			return true;
		}
	}return false;

}

void Knight::getAllMoves(int row, int col)
{
	avMoves.clear();
	Square* s = b.board[row][col];
	Piece* p = s->piece;
	if (row + 2 < 8 && col - 1 >= 0)
	{
		s = b.board[row + 2][col - 1];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row + 1 < 8 && col - 2 >= 0)
	{
		s = b.board[row + 1][col - 2];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row - 1 >= 0 && col - 2 >= 0)
	{
		s = b.board[row - 1][col - 2];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row - 2 >= 0 && col - 1 >= 0)
	{
		s = b.board[row - 2][col - 1];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row - 2 >= 0 && col + 1 < 8)
	{
		s = b.board[row - 2][col + 1];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row - 1 >= 0 && col + 2 < 8)
	{
		s = b.board[row - 1][col + 2];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row + 2 < 8 && col + 1 < 8)
	{
		s = b.board[row + 2][col + 1];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	if (row + 1 < 8 && col + 2 < 8)
	{
		s = b.board[row + 1][col + 2];
		if ((s->getPiece() == nullptr))
		{

			avMoves.push_back(s);
		}
		else if (s->getPiece() != nullptr && p->isWhite() != s->getPiece()->isWhite())
		{

			if (s->getPiece()->getName() == 'K')
				attack = true;
			avMoves.push_back(s);
		}
	}
	cout << "----------------------------" << avMoves.size() << endl;
}

vector<Square*> Knight::getVec()
{
	return avMoves;
}

void Knight::setVec(vector<Square*>& moves)
{
	avMoves = moves;
}
