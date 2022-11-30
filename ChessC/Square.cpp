#include "Square.h"
#include <iostream>

using namespace std;

PiecePtr Square::getPiece()
{
	return piece;

}

void Square::move(int nrow, int ncol)
{
	if (piece->move(row, col, nrow, ncol)) {
		cout << "moving" << endl; //nbdl pointers
	}
	else {
		cout << "cannot move" << endl;
	}
}

Square::Square()
{
}

Square::Square(PiecePtr piece)
{
	this->piece = piece;
}

