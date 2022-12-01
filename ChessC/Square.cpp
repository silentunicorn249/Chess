#include "Square.h"
#include <iostream>

using namespace std;
Square::Square()
{
}

Square::Square(Piece* piece)
{
	this->piece = piece;
}

Piece* Square::getPiece()
{
	return piece;

}

void Square::move(int nrow, int ncol)
{
	if (nrow < 8 && ncol < 8)
	{
		if (piece->move(row, col, nrow, ncol)) {
			cout << "moving" << endl; //nbdl pointers
		}
		else {
			cout << "cannot move" << endl;
		}
	}
}



