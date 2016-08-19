#include "BoardSquare.h"



BoardSquare::BoardSquare()
{
}


BoardSquare::~BoardSquare()
{
}

ChessPiece BoardSquare::getPiece()
{
	return m_currentPiece;
}

void BoardSquare::setPiece(ChessPiece piece)
{
	m_currentPiece = piece;
}
