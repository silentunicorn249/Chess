#include "DEMOO.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <bitset>
#include "Board.h"
#include "Rook.h"
#include "gBoard.h"
#include "AllPossibleMoves.h"
#include "gPossible.h"

using namespace std;
Board b = Board();
vector<vector<Square*>> Blackvec;
vector<vector<Square*>> Whitevec;
vector<Square*>WhiteAttackerMoves;
vector<Square*>BlackAttackerMoves;
vector<Square*>WhiteKingMoves;
vector<Square*>BlackKingMoves;
vector<Square*>PossibleSolutions;
Square* BlackAttackerLoc;
Square* BlackKingLoc;
Square* WhiteAttackerLoc;
Square* WhiteKingLoc;
int CountWhiteAttack;
int CountBlackAttack;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DEMOO w;
    w.show();
    return a.exec();
}
