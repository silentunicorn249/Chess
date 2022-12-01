#include "Piece.h"

Piece::Piece(bool white = true, bool motion = false,bool attack =false)
{

	this->white = white;
	this->motion = motion;
	this->attack = attack;
}

bool Piece::isMoved()
{
	return motion;
}

void Piece::setMove(bool motion)
{
	this->motion = motion;
}

bool Piece::isAttack()
{
	return false;
}



bool Piece::isWhite()
{
	return white;
}

