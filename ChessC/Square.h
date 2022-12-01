#pragma once
#include "Piece.h"


typedef Piece* PiecePtr;

class Square
{
public:
	Square();
	Square(int row,int col,PiecePtr piece);
	PiecePtr getPiece();
	PiecePtr piece = nullptr;
	void move(int nrow, int ncol);
private:
	void Exchange(Square* oldptr, Square* newptr);
	int row;
	int col;

};

