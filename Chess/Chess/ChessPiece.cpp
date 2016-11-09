#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


ChessPiece::~ChessPiece()
{
}

char ChessPiece::getPieceColor()
{
	return m_pieceColor;
}

void ChessPiece::setPieceColor(char color)
{
	m_pieceColor = color;
}

void ChessPiece::availableMoves(int row, int column)
{
	//get all possible moves from location passed in.
}

std::string ChessPiece::EnumToString(PieceType piece)
{
	switch (piece)
	{
	case PieceType::KING:   return "King";
	case PieceType::QUEEN:  return "Queen";
	case PieceType::ROOK:   return "Rook";
	case PieceType::KNIGHT: return "Knight";
	case PieceType::PAWN:   return "Pawn";
	case PieceType::BISHOP: return "Bishop";
	default:
		break;
	}
	return std::string();
}

char ChessPiece::getPieceType()
{
	return m_PieceType;
}

void ChessPiece::setPieceType(char type)
{
	m_PieceType = type;
}

std::string ChessPiece::toString()
{
	std::string output = std::string(1,m_PieceType);
	output.append(std::string(1,m_pieceColor));
	return output;
}
