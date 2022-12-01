#include "Square.h"
#include <iostream>
#include"gBoard.h"
using namespace std;
Square::Square()
{
}

Square::Square(int row, int col,  PiecePtr piece)
{
	this->col = col;
	this->row = row;
	this->piece = piece;
}

Piece* Square::getPiece()
{
	return piece;

}

/*check adjacent*/
void Square::move(int nrow, int ncol)
{
	if (piece!=nullptr)
	{
		if (nrow < 8 && ncol < 8)
		{
			if (piece->move(row, col, nrow, ncol)) {
				piece->setMove(true);
				Exchange(b.board[row][col], b.board[nrow][ncol]);
				cout << "moving" << endl;
			}
			else {
				cout << "cannot move" << endl;
			}
		}
	}
	else
	{
		cout << "cannot move an empty square" << endl;
	}
}

void Square::Exchange(Square* oldptr, Square* newptr)
{
	newptr->piece = oldptr->piece;
	oldptr->piece=nullptr;

}



