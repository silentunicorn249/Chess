#include "Checkmate.h"
#include <iostream>
using namespace std;

Checkmate::Checkmate() {}

void Checkmate::AllPossibleMoves()
{
	Blackvec.clear();
	Whitevec.clear();
	Square* ptr;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ptr = b.board[i][j];
			if (ptr->getPiece() != nullptr)
			{
				if (!(ptr->getPiece()->isWhite()))
					Blackvec.push_back(ptr->getPiece()->getVec());
				else
					Whitevec.push_back(ptr->getPiece()->getVec());
			}

		}
	}
	for (int i = 0; i < Whitevec.size(); i++) {
		for(int j =0; j < Whitevec[i].size(); i++){
			cout << Whitevec[i][j]->getRow() << " " << Whitevec[i][j]->getCol();
		}
		cout << endl;
	}


}

vector<vector<Square*>> Checkmate::getBlackvec()
{
	return Blackvec;
}

vector<vector<Square*>> Checkmate::getWhitevec()
{
	return Whitevec;
}
