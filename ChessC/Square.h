#pragma once
#include "Piece.h"
#include <ostream>


using namespace std;

typedef Piece* PiecePtr;

class Square
{
public:
	Square();
	Square(int row,int col,PiecePtr piece);
	PiecePtr getPiece();
	PiecePtr piece = nullptr;
	void move(int nrow, int ncol);
	void display(ostream& out);
	int getCol();
	int getRow();
private:
	void Exchange(Square* oldptr, Square* newptr);
	int row;
	int col;

};
//ostream &operator<<(ostream& out, Square& sq) {
//	sq.display(out);
//	return out;
//}
