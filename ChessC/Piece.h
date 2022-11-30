#pragma once
#include <bitset>

class Piece
{
public:
	template <int> class bitset;
	Piece(bool white);
	virtual bool move(int orow, int ocol, int nrow, int ncol) = 0;
	bool isWhite();

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


