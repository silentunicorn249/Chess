// ChessC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include "Board.h"
#include "Rook.h"
#include "gBoard.h"

Board b;

using namespace std;

int main()
{
	b = Board();
	b.board[1][0]->move(1,1);
	b.board[1][0]->move(2,1);
		
}
