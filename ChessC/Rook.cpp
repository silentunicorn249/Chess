#include "Rook.h"
#include <iostream>
#include"gBoard.h"

using namespace std;

char Rook::getName()
{
	return 'R';
}

Rook::Rook(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Rook::move(int orow, int ocol, int nrow, int ncol)
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

void Rook::getAllMoves(int row, int col) {
	Square* ptr;
	avMoves.clear();
	for (int i = col + 1; i < 8; i++) {
		ptr = b.board[row][i];
		if (!(ptr->getPiece())) {
			avMoves.push_back(ptr);

		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = col - 1; i >= 0; i--) {
		ptr = b.board[row][i];
		if (!(ptr->getPiece())) {
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = row + 1; i < 8; i++) {
		ptr = b.board[i][col];
		if (!(ptr->getPiece())) {
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);
			}
			break;
		}
	}
	for (int i = row - 1; i >= 0; i--) {
		ptr = b.board[i][col];
		if (!(ptr->getPiece())) {
			avMoves.push_back(ptr);
		}
		else {
			if (isWhite() != ptr->getPiece()->isWhite()) {
				if (ptr->getPiece()->getName() == 'K')
					attack = true;
				avMoves.push_back(ptr);
			}
			break;
		}
	}
}

vector<Square*> Rook::getVec()
{
	return avMoves;
}

