#pragma once
#include "Piece.h"


typedef Piece* PiecePtr;


class Square
{
public:
	Square();
	Square(PiecePtr next);
	PiecePtr getPiece();
	PiecePtr piecePointer;

private:
	/*int row;
	int col;*/


};

