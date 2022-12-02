#include "Board.h"
#include "Square.h"
#include "Rook.h"
#include "Knight.h"
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include <iostream>

using namespace std;

Board::Board()
{
	Piece* black[8] = {
		new Rook(0,0,0),
		new Knight(0,0,0),
		new Bishop(0,0,0),
		new Queen(0,0,0),
		new King(0,0,0),
		new Bishop(0,0,0),
		new Knight(0,0,0),
		new Rook(0,0,0)
	};
	Piece* white[8] = {
		new Rook(1,0,0),
		new Knight(1,0,0),
		new Bishop(1,0,0),
		new Queen(1,0,0),
		new King(1,0,0),
		new Bishop(1,0,0),
		new Knight(1,0,0),
		new Rook(1,0,0)
	};
	for (int i = 0; i < 8; i++) {
		board[0][i] = new Square(0,i,black[i]);
		board[1][i] = new Square(1,i,new Pawn(0,0,0));
		board[7][i] = new Square(7,i,white[i]);
		board[6][i] = new Square(6,i,new Pawn(1,0,0));
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new Square(i,j,nullptr);
		}
	}

}

void Board::display()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((board[i][j]->piece == nullptr))
			{
				cout << ' ';
				continue;
			}
			cout << board[i][j]->getPiece()->getName();
		}
		cout << endl;
	}
	cout << endl;
}
