#include "Players.h"
Players::Players()
{}

void Players::ChangeTurn()
{
	check.AllPossibleMoves();
	turn = !turn;
}

bool Players::getTurn()
{
	return turn;
}
