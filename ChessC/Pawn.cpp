#include "Pawn.h"
#include "Piece.h"
#include <iostream>
#include "Square.h"
#include "gBoard.h"
#include <vector>
using namespace std;

char Pawn::getName()
{
	return 'P';
}

Pawn::Pawn(bool white,bool motion,bool attack) : Piece(white,motion, attack) {

}

bool Pawn::move(int orow, int ocol, int nrow, int ncol)
{
	getAllMoves(orow, ocol);
	cout << endl << avMoves.size() << endl << endl;

	Square* ptr;
	for (int i = 0; i < avMoves.size(); i++) {
		ptr = avMoves[i];
		if ((ptr->getCol() == ncol) && ptr->getRow() == nrow) {
			return true;
		}
	}return false;


}

void Pawn::getAllMoves(int row, int col) {
	Square* ptr;
	avMoves.clear();
	//cout << row << " " << col << " " << avMoves.size();
	int direction = 1;
	if (isWhite()) {
		direction = -1;
	}

	ptr = b.board[row + (direction * 1)][col];
	if (!(ptr->getPiece())) { //normal condition
		avMoves.push_back(ptr);
		if (!isMoved()) {  //first move condition
			ptr = b.board[row + (direction * 2)][col];
			if (!(ptr->getPiece())) {
				avMoves.push_back(ptr);
			}

		}
	}
	if (col < 7) {
		ptr = b.board[(row + (direction * 1))][(col + 1)];
		if (ptr->getPiece()) {
			if (isWhite() != ptr->getPiece()->isWhite()) { //attacking right condition 
				avMoves.push_back(ptr);
				cout << "Pawn attacked right" << endl;
			}
		}
	}
	if (col > 0) {
		ptr = b.board[(row + direction * 1)][(col - 1)];
		if (ptr->getPiece()) {
			if (isWhite() != ptr->getPiece()->isWhite()) { //attacking left condition 
				avMoves.push_back(ptr);
				cout << "Pawn attacked left" << endl;
			}
		}
	}
}

vector<Square*> Pawn::getVec()
{
	return avMoves;
}
	


//bool Pawn::move(int orow, int ocol, int nrow, int ncol)
//{
//
//	Square* s = b.board[nrow][ncol];
//	Piece* p = s->getPiece();
//	int diffcol = abs(orow-nrow);
//	int diffrow = nrow-orow;
//	if ((diffrow>0 && isWhite()) || (diffrow < 0 && !isWhite())) //bool isAttack
//	{
//		return false;
//	}
//	diffrow = abs(diffrow);
//	/*check for square availability to be moved to*/
//	if (p == nullptr) 
//	{
//		/*first move check*/
//		if ((diffrow<=2 && !isMoved()) || (diffrow==1 && isMoved())) //bool ismoved
//		{
//			return true;
//		}
//		return false;
//	}
//	if (p->isWhite() == isWhite()) {
//		return false;
//	}
//	else if (diffrow == 1 && diffcol == 1 && p->isWhite() != isWhite())
//	{
//		return true;
//	}
//}

