#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Pawn::~Pawn()
{
}

std::vector<Point> Pawn::getMoves(int row, int column)
{
	if (m_pieceColor == 'l') 
	{
		if (hasMoved) 
		{
			if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
			{
				validMoves.push_back(Point(row - 1, column));
			}
		}
		else 
		{
			if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row - 1, column));
			}
			if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row - 2, column));
			}
		}
	}
	else if (m_pieceColor == 'd') 
	{
		if (hasMoved)
		{
			if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row + 1, column));
			}
		}
		else
		{
			if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row + 1, column));
			}
			if (!ChessBoard::getBoardSquare(row + 2, column)->getOccupied())
			{
				validMoves.push_back(Point(row + 2, column));
			}
		}
	}
	return validMoves;
}
