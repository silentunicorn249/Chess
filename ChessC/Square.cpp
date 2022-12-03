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
		if (nrow < 8 && ncol < 8) //tetshal fel GUI
		{
			if (nrow == row && ncol == col) {
				cout << "Moving in same place" << endl;
				return;
			}
			if (piece->move(row, col, nrow, ncol)) {
				piece->setMove(true);
				//cout << b.board[row][col]->getPiece()->getName();
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

void Square::display(ostream& out)
{
	cout << this->getPiece()->getName();
}

void Square::Exchange(Square* oldptr, Square* newptr)
{
	newptr->piece = oldptr->piece;
	oldptr->piece=nullptr;

}
int Square::getCol() {
	return col;
 }

int Square::getRow() {
	return row;
}

