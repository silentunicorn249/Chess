#pragma once
#include "Piece.h"
#include "Square.h"


class Bishop : Piece
{
public:
	void move(int row, int column);

private:
	SqaurePtr NW;
	SqaurePtr NE;
	SqaurePtr SW;
	SqaurePtr SE;

};

