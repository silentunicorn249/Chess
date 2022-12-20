#include "Check.h"
#include <iostream>
#include <vector>
#include "gPossible.h"
#include"gBoard.h"
#include <algorithm>
#include <iterator>
using namespace std;

/*void Checkmate::AllPossibleMoves()
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
		for (int j = 0; j < Whitevec[i].size(); i++) {
			cout << Whitevec[i][j]->getRow() << " " << Whitevec[i][j]->getCol();
		}
		cout << endl;
	}


}
*/


bool checkWhite() {	//White King is in danger
	Square* ptr;
	CountBlackAttack = 0;
	bool found = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ptr = b.board[i][j];
			if (!(ptr->getPiece()==nullptr))
			{
				if (ptr->getPiece()->getName() == 'K')
				{
					if (ptr->getPiece()->isWhite())
					{
						WhiteKingLoc = ptr;
						WhiteKingMoves = ptr->getPiece()->getVec();
					}
				}
				if (ptr->getPiece()->isAttack())
				{
					if (!(ptr->getPiece()->isWhite())) //black is attacking white king 
					{
						CountBlackAttack++;
						BlackAttackerLoc = ptr;
						BlackAttackerMoves = ptr->getPiece()->getVec();
						found = true;
					}

				}
			}
		}
	}

	return found;
}
bool checkBlack() {	//Black King is in danger
	Square* ptr;
	CountWhiteAttack = 0;
	bool found = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ptr = b.board[i][j];
			if (!(ptr->getPiece() == nullptr))
			{
				if (ptr->getPiece()->getName() == 'K')
				{
					if (!(ptr->getPiece()->isWhite()))
					{
						BlackKingLoc = ptr;
						BlackKingMoves = ptr->getPiece()->getVec();
					}
				}
				if (ptr->getPiece()->isAttack())
				{
					if (ptr->getPiece()->isWhite()) //White is attacking Black king
					{
						CountWhiteAttack++;
						WhiteAttackerLoc = ptr;
						WhiteAttackerMoves = ptr->getPiece()->getVec();
						found = true;
					}

				}
			}
		}
	}

	return found;
}

bool CheckMateWhite()
{
	if (CountBlackAttack == 2)// we will make a new vector for saving available moves of the king
						      // return false when vector.size()>0
	{
		WhiteKingIter();
		if (PossibleSolutions.size() == 0)
			return true;
		///////////////////Check for Backtrack
		else return false;
	}
	else if (CountBlackAttack == 1)
	{
		//first_Case:
		WhiteKingIter();
		//second_Case (Kill attacker)
		for (int i = 0; i < Whitevec.size(); i++)
		{
			for (int j = 0; i < Whitevec[j].size(); j++)
			{
				if (BlackAttackerLoc->getRow() == Whitevec[i][j]->getRow() &&
					BlackAttackerLoc->getCol() == Whitevec[i][j]->getCol())
				{
					
					ChangeBoardState(b, Whitevec[i][j]->getRow(), Whitevec[i][j]->getCol());
				}
			}
			
		}
		
		
		
		//if (ChangeBoardState)
		//{
			//PossibleSolutions.push_back();
		//}
	}
	else return false;
}

bool ChangeBoardState(Board& oldBoard,int row, int col)
{
	Board b2(oldBoard);//backup Board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			b.board[i][j]->move(row, col);
			if (checkWhite())
			{
				////////////////////////////////////////////////////////////////
			}
			b = b2;////////////////////////////////////////////////////////////
		}
		
	}
	
	return false;
}

void WhiteKingIter() 
{
	
	//SortVec();

	for (int i = 0; i < WhiteKingMoves.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < Blackvec.size(); j++)
		{
			for (int k = 0; k < Blackvec[j].size(); k++)
			{
				if (WhiteKingMoves[i]->getRow() == Blackvec[j][k]->getRow() 
					&& (WhiteKingMoves[i]->getCol() == Blackvec[j][k]->getCol()))
					found = true;
			
			}
		}
		if (!found)
		{
			PossibleSolutions.push_back(WhiteKingMoves[i]);
		}
	}
	
}

void SortVec()
{
	sort(WhiteKingMoves.begin(), WhiteKingMoves.end(),compareSquare);
	for(int i =0; i < Blackvec.size(); i++)
	sort(Blackvec[i].begin(), Blackvec[i].end(), compareSquare);
	
}

bool compareSquare(Square* s1, Square* s2)
{
	return (s1->getRow() < s2->getRow());
}