#include "Square.h"

PiecePtr Square::getPiece()
{
	return piecePointer;

}

Square::Square()
{
	piecePointer = nullptr;
}

Square::Square(PiecePtr piece){
	piece->currentSquare = this;
}
