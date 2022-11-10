// ChessC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rook.h"
#include <bitset>
using namespace std;

int main()
{
    //cout << "Hello World!\n";
    Square s;
    Rook r(true);
    s.piecePointer = &r;
    cout << r.currentSquare << endl;
    cout << &s;
}
