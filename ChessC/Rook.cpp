#include "Rook.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char Rook::getName()
{
	return 'R';
}

Rook::Rook(bool white , bool motion, bool attack) : Piece(white, motion, attack){
	
}

//bool Rook::move(int orow, int ocol, int nrow, int ncol)
//{
//
//	int diffrow = abs(nrow - orow);
//	int diffcol = abs(ncol - ocol);
//	int temp;
//	Square* s = b.board[nrow][ncol];
//	Piece* p = s->getPiece();
//	Square* ptr;
//
//	/*XOR used to ensure that the diffrow and diffcol are never equal tp ensure the rook's linear movement*/
//	if (!(p == nullptr)) {
//		if (p->isWhite() == isWhite()) {
//			return false;
//		}
//	}
//
//
//	
//	if (!(diffrow > 0 && diffcol > 0) ||
//		!(diffrow==0 && diffcol==0) ) //ToDo:check for adjacent squares
//	{
//		if(diffcol)
//		{
//			if (ncol < ocol)
//			{
//				temp = ncol;
//				ncol = ocol;
//				ocol = temp;
//			}
//			for (int i = ocol + 1; i < ncol; i++) {
//				ptr = b.board[orow][i];
//				if (ptr->getPiece()) {
//					return false;
//				}
//			}
//		}
//		if (diffrow) {
//			if (nrow < orow)
//			{
//				temp = nrow;
//				nrow = orow;
//				orow = temp;
//			}
//			for (int i = orow + 1; i < nrow; i++) {
//				ptr = b.board[i][ocol];
//				if (ptr->getPiece()) {
//					return false;
//				}
//			}
//		}
//
//		return true;
//	}
//	cout << "Unexcpected call" << endl;
//	return false;
//}

bool Rook::move(int orow, int ocol, int nrow, int ncol)
{
	getAllMoves(orow, ocol);
	cout << endl << avMoves.size() << endl << endl;

	Square* ptr;
	for (int i = 0; i < avMoves.size(); i++) {
		ptr = avMoves[i];
		if (ptr-> col == ncol && ptr->row == nrow) {
			return true;
		}
	}return false;


}

void Rook::getAllMoves(int row, int col) {
	Square* ptr;
	avMoves.clear();
	cout << row << " " << col << " " << avMoves.size();
	int n, s, e, w = 0;
	for (int i = col + 1; i < 8; i++) {
		ptr = b.board[row][i];
		if (!(ptr->getPiece())) {
			cout << "right" << endl;
			avMoves.push_back(ptr);

		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = col - 1; i >= 0; i--) {
		ptr = b.board[row][i];
		if (!(ptr->getPiece())) {
			cout << "left" << endl;
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = row + 1; i < 8; i++) {
		ptr = b.board[i][col];
		if (!(ptr->getPiece())) {
			cout << "down" << endl;
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = row - 1; i >= 0; i--) {
		ptr = b.board[i][col];
		if (!(ptr->getPiece())) {
			cout << "up" << endl;
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				avMoves.push_back(ptr);
			}
			break;
		}
	}
}

