#include "Knight.h"
#include "ChessBoard.h"


Knight::Knight()
{
}

Knight::Knight(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Knight::~Knight()
{
}

std::vector<Point> Knight::getMoves(int row, int column)
{
	if (ChessBoard::validSquare(row + 1, column + 2)) 
	{
		if (ChessBoard::getBoardSquare(row + 1, column + 2)->getPiece()->getPieceColor() != this->getPieceColor())
		{
			validMoves.push_back(Point(row + 1, column + 2));
		}
	}
	if(ChessBoard::validSquare(row + 1, column - 2))
	{
			if (!ChessBoard::getBoardSquare(row + 1, column - 2)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + 1, column - 2));
			}
	}
	if (ChessBoard::validSquare(row + 2, column + 1)) 
	{

		if (!ChessBoard::getBoardSquare(row + 2, column + 1)->getPiece()->getPieceColor() != this->getPieceColor())
		{
			validMoves.push_back(Point(row + 2, column + 1));
		}
	}
	if(ChessBoard::validSquare(row + 2, column - 1))
	{
			if (!ChessBoard::getBoardSquare(row + 2, column - 1)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + 2, column - 1));
			}
	}
	if (ChessBoard::validSquare(row - 1, column + 2)) 
	{
		if (!ChessBoard::getBoardSquare(row - 1, column + 2)->getPiece()->getPieceColor() != this->getPieceColor())
		{
			validMoves.push_back(Point(row - 1, column + 2));
		}
	}
	if(ChessBoard::validSquare(row - 1, column - 2))
	{
			if (!ChessBoard::getBoardSquare(row - 1, column - 2)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row - 1, column - 2));
			}
	}
	if (ChessBoard::validSquare(row - 2, column + 1)) 
	{
		if (!ChessBoard::getBoardSquare(row - 2, column + 1)->getPiece()->getPieceColor() != this->getPieceColor())
		{
			validMoves.push_back(Point(row - 2, column + 1));
		}
	}
	if(ChessBoard::validSquare(row - 2, column - 1))
	{
			if (!ChessBoard::getBoardSquare(row - 2, column - 1)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row - 2, column - 1));
			}
	}
	return validMoves;
}
