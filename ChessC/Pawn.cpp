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
    rl = false;
    getAllMoves(orow, ocol);


    Square* ptr;


    int diffrow = orow - nrow;
    int diffcol = abs(ocol - ncol);
    int direction = 1;
    if (isWhite()) {
        direction = -1;
    }
    if ((isWhite() && diffrow < 0) || (!isWhite() && diffrow > 0)) {
        return false;
    }
    diffrow = abs(orow - nrow);
    if (diffcol != 0 && !rl) {
        return false;
    }
    if (diffrow > 2) {
        return false;
    }
    if (diffrow == 2) {
        ptr = b.board[orow + (direction * 1)][ocol];
        if (!isMoved()) {
            if (!(ptr->getPiece())) {
                ptr = b.board[orow + (direction * 2)][ocol];
                if (!(ptr->getPiece())) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }

        }
        else { return false; }
    }

    //Normal condition
    ptr = b.board[orow + direction][ocol];
    if (!(ptr->getPiece())) {
        return true;
    } 
    else {
        return false;
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
    rl = false;
    Square* ptr;
    avMoves.clear();


    //cout << row << " " << col << " " << avMoves.size();
    int direction = 1;
    if (isWhite()) {
        direction = -1;
    }


    if (col < 7) {
        ptr = b.board[row + direction][(col + 1)];
        if (ptr->getPiece()) {
            if (isWhite() != ptr->getPiece()->isWhite()) { //attacking right condition 

                if (ptr->getPiece()->getName() == 'K')
                    attack = true;
                rl = true;
                avMoves.push_back(ptr);
            }
        }
        else avMoves.push_back(ptr);
    }
    if (col > 0) {
        ptr = b.board[row + direction][(col - 1)];
        if (ptr->getPiece()) {
            if (isWhite() != ptr->getPiece()->isWhite()) { //attacking left condition
                if (ptr->getPiece()->getName() == 'K')
                    attack = true;
                rl = true;
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

void Pawn::setVec(Board& bTest,vector<Square*>& moves)
{
    for (int i = 0; i < moves.size(); i++) {

        int row = moves[i]->getRow();
        int col = moves[i]->getCol();

        avMoves.push_back(bTest.board[row][col]);
    }
}


