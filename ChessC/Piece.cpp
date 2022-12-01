#include "Piece.h"

Piece::Piece(bool white = true, bool motion = false, bool attack = false)
{

	this->white = white;
	this->attack = attack;
	this->motion = motion;
}

bool Piece::isMoved()
{
	return motion;
}

bool Piece::isAttack()
{
	return attack;
}

bool Piece::isWhite()
{
	return white;
}

