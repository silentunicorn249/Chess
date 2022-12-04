#include "AllPossibleMoves.h"
#include<vector>
#include"Square.h"
#include"gBoard.h"
#include"Board.h"
#include <iostream>

using namespace std;

vector<vector<Square*>> Blackvec;
vector<vector<Square*>> Whitevec;

void AllPossibleMoves()
{
	cout << "STarting allmoves" << endl;
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
				ptr->getPiece()->getAllMoves(
					ptr->getRow(),
					ptr->getCol()
				);
				if (!(ptr->getPiece()->isWhite()))
				{
					Blackvec.push_back(ptr->getPiece()->getVec());
				}
				else
				{
					Whitevec.push_back(ptr->getPiece()->getVec());
				}
			}

		}
	}
	cout << Whitevec.size() << endl;
	for (int i = 0; i < Whitevec.size(); i++) {
		for (int j = 0; j < Whitevec[i].size(); j++) {
			cout << Whitevec[i][j]->getRow() << ", " << Whitevec[i][j]->getCol() << endl;
		}
		cout << "ended piece" << endl;
	}


}

