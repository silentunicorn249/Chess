#include "Piece.h"

Piece::Piece(bool white = 1)
{
	
	this->white = white;
}

bool Piece::isWhite()
{
	return white;
}

