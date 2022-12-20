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

Pawn::Pawn(bool white, bool motion, bool attack) : Piece(white, motion, attack) {

}

bool Pawn::move(int orow, int ocol, int nrow, int ncol)
{
    getAllMoves(orow, ocol);


    Square* ptr;
   

    int diffrow = abs(orow - nrow);
    int direction = 1;
    if (isWhite()) {
        direction = -1;
    }
    if (diffrow == 2) {
        if (!isMoved()) {  //first move condition
            ptr = b.board[orow + (direction * 2)][ocol];
            if (!(ptr->getPiece())) {
                return true;
            }
        }
        else return false;
    }
    ptr = b.board[orow + (direction * 1)][ocol];
    if (!(ptr->getPiece())) { //normal condition
        return true;
    }
    
    for (int i = 0; i < avMoves.size(); i++) {
        ptr = avMoves[i];
        if ((ptr->getCol() == ncol) && ptr->getRow() == nrow) {
            return true;
        }
    }
    return false;


}

void Pawn::getAllMoves(int row, int col) {
    Square* ptr;
    avMoves.clear();
    //cout << row << " " << col << " " << avMoves.size();
    int direction = 1;
    if (isWhite()) {
        direction = -1;
    }


    if (col < 7) {
        ptr = b.board[(row + (direction * 1))][(col + 1)];
        if (ptr->getPiece()) {
            if (isWhite() != ptr->getPiece()->isWhite()) { //attacking right condition 

                if (ptr->getPiece()->getName() == 'K')
                    attack = true;
                avMoves.push_back(ptr);
            }
        }
        else avMoves.push_back(ptr);
    }
    if (col > 0) {
        ptr = b.board[(row + direction * 1)][(col - 1)];
        if (ptr->getPiece()) {
            if (isWhite() != ptr->getPiece()->isWhite()) { //attacking left condition
                if (ptr->getPiece()->getName() == 'K')
                    attack = true;
                avMoves.push_back(ptr);
            }
        }
        else avMoves.push_back(ptr);
    }
}

vector<Square*> Pawn::getVec()
{
    return avMoves;
}


