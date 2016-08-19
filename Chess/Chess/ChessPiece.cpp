#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}


ChessPiece::~ChessPiece()
{
}

char ChessPiece::getPieceType()
{
	return m_pieceType;
}

void ChessPiece::setPieceType(char pieceType)
{
	m_pieceType = pieceType;
}

char ChessPiece::getPieceColor()
{
	return m_pieceColor;
}

void ChessPiece::setPieceColor(char color)
{
	m_pieceColor = color;
}
