// ChessC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "Board.h"
#include "Rook.h"
#include "gBoard.h"
#include "AllPossibleMoves.h"
#include "gPossible.h"
#include "Check.h"

using namespace std;
Board b = Board();

int main()
{
	//Checkmate Scenario
	//b.board[6][4]->move(4, 4);
	//b.board[7][4]->move(6, 4);
	//b.board[6][4]->move(5, 4);
	//b.board[1][2]->move(3, 2);
	////b.board[0][3]->move(2, 1);	
	//b.board[1][6]->move(3, 6);
	//b.board[0][5]->move(2, 7);
	//b.board[2][2]->move(3, 2);
	//b.board[3][2]->move(4, 2);
	//b.board[3][6]->move(4, 6);
	//b.board[7][5]->move(6, 4);
	//b.board[1][3]->move(3, 3);
	//b.board[2][1]->move(4, 3);
	//b.board[1][4]->move(3, 4);

	
	b.board[6][6]->move(4, 6);
	b.board[6][5]->move(4, 5);
	b.board[1][4]->move(3, 4);
	b.board[0][3]->move(4, 7);
	b.board[7][6]->move(5, 5);

	checkWhite();
	cout << "\n"<<"IS IT CHECKMATE?????>>>>>"<<CheckMateWhite()<<endl;
	//b.board[4][0]->move(5, 0);
	//b.board[6][1]->move(5, 0);
	//cout << b.board[0][0]->getPiece()->getName();
	/*b.display();

	cout << b.board[0][0]->getPiece()->move(0,0,1,1) << endl;
	cout << b.board[0][0]->getPiece()->move(0,0,0,1) << endl;
	cout << b.board[0][0]->getPiece()->move(0,0,1,0) << endl;
	
	
	cout << b.board[1][0]->getPiece()->move(1,0,4,0) << endl;
	cout << b.board[1][0]->getPiece()->move(1,0,3,0) << endl;
	cout << b.board[1][0]->getPiece()->move(1,0,2,0) << endl;
	cout << b.board[1][0]->getPiece()->move(1,0,1,0) << endl;*/

	//pawn movement
	//b.board[1][0]->move(3,0);
	//b.board[1][0]->move(3,0); //check empty movement
	//b.board[3][0]->move(2,0); //check pawn back movement
	//b.board[3][0]->move(4,0);
	/*cout << b.board[0][0]->getPiece()->move(0,0,5,0) << endl;
	cout << b.board[0][0]->getPiece()->move(0,0,4,0) << endl;
	cout << b.board[0][0]->getPiece()->move(0,0,3,0) << endl;*/
	/*b.board[6][1]->move(5, 1);
	b.board[4][0]->move(5, 0);*/
	////rook movement
	//b.board[0][0]->move(3, 0);
	//b.board[3][0]->move(3, 1);
	//b.board[3][1]->move(5, 1);
	//b.board[5][1]->move(4, 1);
	//b.board[4][1]->move(5, 1);
	//b.board[5][1]->move(5, 0);
	//b.board[5][0]->move(6, 0);
	//b.board[6][0]->move(5, 0);

	//cout << b.board[0][2]->getPiece()->move(0, 2, 3, 5) << endl;
	//b.board[6][3]->move(5, 3);
	//b.board[7][2]->move(2, 7);

	//b.board[0][6]->move(2, 7);

	//b.board[7][2]->move(5,4);
	//AllPossibleMoves();
	//b.board[7][1]->move(5, 2);
	//AllPossibleMoves();

	//b.board[0][1]->move(2, 0);
	b.display();


		
}
