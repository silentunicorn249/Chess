#pragma once
#include<vector>
#include"Square.h"
#include"gBoard.h"
#include"Board.h"
class Checkmate
{
public:
	Checkmate();
	void AllPossibleMoves();
	vector<vector<Square*>> getBlackvec();
	vector<vector<Square*>> getWhitevec();
private:
	vector<vector<Square*>> Blackvec;
	vector<vector<Square*>> Whitevec;

};

