#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
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
