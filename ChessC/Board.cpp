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
//Board copy constructor  
Board::Board(const Board& oBoard) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Piece* p = nullptr;
			Piece* np = oBoard.board[i][j]->getPiece();
			if (np == nullptr) {
				//cout << "Creating empty square" << endl;
				board[i][j] = new Square(i, j, nullptr);
				continue;
			}
			if (np->getName() == 'R') {
				//cout << "Creating Rook" << endl;
				p = new Rook(np->isWhite(), np->isMoved(), np->isAttack());
			}
			else if (np->getName() == 'N') {
				//cout << "Creating Knight" << endl;
				p = new Knight(np->isWhite(), np->isMoved(), np->isAttack());
			}
			else if (np->getName() == 'B') {
				//cout << "Creating Bishop" << endl;
				p = new Bishop(np->isWhite(), np->isMoved(), np->isAttack());
			}
			else if (np->getName() == 'Q') {
				//cout << "Creating Queen" << endl;
				p = new Queen(np->isWhite(), np->isMoved(), np->isAttack());
			}
			else if (np->getName() == 'K') {
				//cout << "Creating King" << endl;
				p = new King(np->isWhite(), np->isMoved(), np->isAttack());
			}
			else if (np->getName() == 'P') {
				//cout << "Creating Pawn" << endl;
				p = new Pawn(np->isWhite(), np->isMoved(), np->isAttack());
			}
			//cout << "Assigning piece" << endl;
			Square* s = new Square(i, j, p);
			this->board[i][j] = s;

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
