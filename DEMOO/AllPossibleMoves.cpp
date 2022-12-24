#include "AllPossibleMoves.h"
#include<vector>
#include"Square.h"
#include"gBoard.h"
#include"Board.h"
#include <iostream>
//#include "gPossible.h"

using namespace std;

void AllPossibleMoves()
{
	//cout << "STarting allmoves" << endl;
	b.Blackvec.clear();
	b.Whitevec.clear();
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
					b.Blackvec.push_back(ptr->getPiece()->getVec());
				}
				else
				{
					b.Whitevec.push_back(ptr->getPiece()->getVec());
				}
			}

		}
	}
	/*cout << Blackvec.size() << endl;
	for (int i = 0; i < Blackvec.size(); i++) {
		for (int j = 0; j < Blackvec[i].size(); j++) {
			cout << Blackvec[i][j]->getRow() << ", " << Blackvec[i][j]->getCol() << endl;

		}

		cout << "ended piece " <<endl;
	}*/


}
