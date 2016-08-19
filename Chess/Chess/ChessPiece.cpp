#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}


ChessPiece::~ChessPiece()
{
}

std::string ChessPiece::getPieceType()
{
	return m_pieceType;
}

void ChessPiece::setPieceType(std::string pieceType)
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

void ChessPiece::getMoves(int row, int column)
{
	//get all possible moves from location passed in.
}
