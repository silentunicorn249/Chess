#pragma once
#include"Checkmate.h"
class Players
{
	Players();
	void ChangeTurn();
	bool getTurn();
private:

	/*turn -> 0(white)*/
	Checkmate check;
	bool turn;
	bool endgame;
};

