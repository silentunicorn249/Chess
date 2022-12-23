#pragma once
#include <vector>

using namespace std;

class Square;
class Board;
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
	virtual vector<Square*> getVec() = 0;
	virtual void setVec(Board& bTest, vector<Square*>& moves) = 0;


protected:
	bool white;
	bool motion; //this should be changed in the children classes to true if the move function returns true
	bool attack;
	//todo: clean code

private:

};
