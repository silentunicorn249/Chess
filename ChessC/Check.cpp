#include "Check.h"
#include <iostream>
#include <vector>
//#include "gPossible.h"
#include"gBoard.h"
#include <algorithm>
#include <iterator>
#include "Board.h"
using namespace std;


bool checkWhite() {	//White King is in danger
	Square* ptr;
	b.CountBlackAttack = 0;
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
					if (ptr->getPiece()->isWhite())
					{
						b.WhiteKingLoc = ptr;
						b.WhiteKingMoves = ptr->getPiece()->getVec();
					}
				}
				if (ptr->getPiece()->isAttack())
				{
					if (!(ptr->getPiece()->isWhite())) //black is attacking white king 
					{
						b.CountBlackAttack++;
						b.BlackAttackerLoc = ptr;
						b.BlackAttackerMoves = ptr->getPiece()->getVec();
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
	b.CountWhiteAttack = 0;
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
						b.BlackKingLoc = ptr;
						b.BlackKingMoves = ptr->getPiece()->getVec();
					}
				}
				if (ptr->getPiece()->isAttack())
				{
					if (ptr->getPiece()->isWhite()) //White is attacking Black king
					{
						b.CountWhiteAttack++;
						b.WhiteAttackerLoc = ptr;
						b.WhiteAttackerMoves = ptr->getPiece()->getVec();
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
	// we will make a new vector for saving available moves of the king
	// return false when vector.size()>0
	if (b.CountBlackAttack == 2)
	{
		WhiteKingIter();
		//King possible not general possible
		if (b.kingPossibleSolutions.size() == 0)
			return true;
		///////////////////Check for Backtrack
		else return false;
	}
	else if (b.CountBlackAttack == 1)
	{
		//first_Case:
		WhiteKingIter();
		//second_Case (Kill attacker)
		for (int i = 0; i < b.Whitevec.size(); i++)
		{
			for (int j = 0; j < b.Whitevec[i].size(); j++)
			{
				if (b.BlackAttackerLoc->getRow() == b.Whitevec[i][j]->getRow() &&
					b.BlackAttackerLoc->getCol() == b.Whitevec[i][j]->getCol())
				{
					ChangeBoardState(b, b.Whitevec[i][j]->getRow(), b.Whitevec[i][j]->getCol());
					i = b.Whitevec.size();
					break;
				}
			}

		}

		//Third case: defend king
		for (int k = 0; k < b.BlackAttackerMoves.size(); k++) {
				ChangeBoardState(b, b.BlackAttackerMoves[k]->getRow(), b.BlackAttackerMoves[k]->getCol());
				//b.display();
		}


		if (b.PossibleSolutions.size() == 0 && b.kingPossibleSolutions.size() == 0) {
			return true;
		}
		else return false;

	}
	else return false;
}

void ChangeBoardState(Board& oldBoard, int row, int col)
{
	Board b3 = Board(oldBoard);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b3.board[i][j]->getPiece() != nullptr)
			{
				if (b3.board[i][j]->getPiece()->isWhite())
				{
					if (b3.board[i][j]->getPiece()->move(i, j, row, col))
					{
						Board b2(oldBoard);//backup Board
						b.board[i][j]->move(row, col);
						/*if ((!checkWhite() && !b.board[i][j]->getPiece()->isWhite()) ||
							(checkBlack() && b.board[i][j]->getPiece()->isWhite())
							)*/
						if (!checkWhite())
						{
							b.display();
							b3.PossibleSolutions.push_back(b.board[i][j]);
						}
						//swap(b, b2);
						b = b2;
					}
				}
			}
		}
		//b = b3;

	}
	//swap(b, b2);
	b = b3;
	b.PossibleSolutions = b3.PossibleSolutions;
}

void swap(Board& B1, Board& B2) {
	B2 = B1;
}

void WhiteKingIter()
{

	//SortVec();

	for (int i = 0; i < b.WhiteKingMoves.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < b.Blackvec.size(); j++)
		{
			for (int k = 0; k < b.Blackvec[j].size(); k++)
			{
				if (b.WhiteKingMoves[i]->getRow() == b.Blackvec[j][k]->getRow()
					&& (b.WhiteKingMoves[i]->getCol() == b.Blackvec[j][k]->getCol())) {
					found = true;
				}

			}
		}
		if (!found)
		{
			Board b2 = Board(b);
			b.board[b.WhiteKingLoc->getRow()][b.WhiteKingLoc->getCol()]->move(b.WhiteKingMoves[i]->getRow(), b.WhiteKingMoves[i]->getCol());
			if (checkWhite()) {
				b = b2;
				continue;
			}
			b = b2;
			b.kingPossibleSolutions.push_back(b.WhiteKingMoves[i]);
		}
	}

}

void SortVec()
{
	sort(b.WhiteKingMoves.begin(), b.WhiteKingMoves.end(), compareSquare);
	for (int i = 0; i < b.Blackvec.size(); i++)
		sort(b.Blackvec[i].begin(), b.Blackvec[i].end(), compareSquare);

}

bool compareSquare(Square* s1, Square* s2)
{
	return (s1->getRow() < s2->getRow());
}