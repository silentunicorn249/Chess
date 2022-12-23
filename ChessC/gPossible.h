#pragma once
#include "Square.h"
#include <vector>

extern vector<vector<Square*>> Blackvec;
extern vector<vector<Square*>> Whitevec;
extern vector<Square*>WhiteAttackerMoves;
extern vector<Square*>BlackAttackerMoves;
extern vector<Square*>WhiteKingMoves;
extern vector<Square*>BlackKingMoves;
extern vector<Square*>PossibleSolutions;
extern vector<Square*>kingPossibleSolutions;
extern Square* BlackAttackerLoc;
extern Square* BlackKingLoc;
extern Square* WhiteAttackerLoc;
extern Square* WhiteKingLoc;
extern int CountWhiteAttack;
extern int CountBlackAttack;
