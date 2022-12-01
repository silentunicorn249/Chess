#include "Board.h"
#include "Square.h"
#include "Rook.h"
#include "Knight.h"
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

Board::Board()
{
	Piece* b[8] = {
		new Rook(0,0,0),
		new Knight(0,0,0),
		new Bishop(0,0,0),
		new Queen(0,0,0),
		new King(0,0,0),
		new Bishop(0,0,0),
		new Knight(0,0,0),
		new Rook(0,0,0)
	};
	Piece* w[8] = {
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
		board[0][i] = new Square(b[i]);
		board[1][i] = new Square(new Pawn(0,0,0));
		board[7][i] = new Square(w[i]);
		board[7][i] = new Square(new Pawn(1,0,0));
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new Square();
		}
	}

}
