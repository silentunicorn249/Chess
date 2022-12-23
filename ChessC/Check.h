#pragma once
#include<vector>
#include"Square.h"
#include"Board.h"

	bool checkWhite();
	bool checkBlack();
	bool CheckMateWhite();
	void WhiteKingIter();
	void SortVec();
	bool compareSquare(Square* s1, Square* s2);
	void ChangeBoardState(Board &oldBoard,int row,int col);
	//vector<vector<Square*>> getBlackvec();
	//vector<vector<Square*>> getWhitevec();

	//vector<vector<Square*>> Blackvec;
	//vector<vector<Square*>> Whitevec;

