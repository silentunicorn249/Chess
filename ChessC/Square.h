#pragma once
#include "Piece.h"


typedef Piece* PiecePtr;

class Square
{
public:
	Square();
	Square(PiecePtr piece);
	PiecePtr getPiece();
	PiecePtr piece = nullptr;
	void move(int nrow, int ncol);

private:
	int row;
	int col;
	int color;

};

