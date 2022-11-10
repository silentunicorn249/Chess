#pragma once
#include <bitset>

typedef Square* SquarePtr;

class Piece
{
public:
	template <int> class bitset;
	bitset<8>b(int pieceType);
	Piece(bool white);
	virtual void move(int row, int column) = 0;
	bool isWhite();
	SquarePtr currentSquare;

protected:
	bool white;
	//todo: clean code
	const int NONE = 0;
	const int KING = 1;
	const int PAWN = 2;
	const int KNIGHT = 4;
	const int BISHOP = 5;
	const int ROOK = 6;
	const int QUEEN = 7;

	const int WHITE = 8;
	const int BLACK = 16;

private:

};


