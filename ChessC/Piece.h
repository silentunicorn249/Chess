#pragma once
#include <vector>
class Square;
class Piece
{
public:
	virtual char getName();
	Piece(bool white, bool motion, bool attack);
	virtual bool move(int orow, int ocol, int nrow, int ncol) = 0;
	bool isMoved();
	void setMove(bool motion);
	bool isAttack();
	bool isWhite();

	virtual void getAllMoves(int row, int col) = 0;
	virtual std::vector<Square*> getVec() = 0;


protected:
	bool white;
	bool motion; //this should be changed in the children classes to true if the move function returns true
	bool attack;
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
