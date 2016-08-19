#include "BoardSquare.h"



BoardSquare::BoardSquare()
{
}

BoardSquare::BoardSquare(ChessPiece piece, std::string backgroundColor)
{
	setPiece(piece);
	setBackgroundColor(backgroundColor);
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

std::string BoardSquare::getBackgroundColor()
{
	return m_backgroundColor;
}

void BoardSquare::setBackgroundColor(std::string backgroundColor)
{
	m_backgroundColor = backgroundColor;
}

bool BoardSquare::getOccupied()
{
	return m_isOccupied;
}

void BoardSquare::setOccupied(bool occupied)
{
	m_isOccupied = occupied;
}
