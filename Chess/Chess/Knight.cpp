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
	if (ChessBoard::validSquare(row + 2, column + 2)) {
		if (row + 1 < ChessBoard::rowMax && column + 2 < ChessBoard::columnMax && column - 2 > 0)
		{
			if (!ChessBoard::getBoardSquare(row + 1, column + 2)->getOccupied())
			{
				validMoves.push_back(Point(row + 1, column + 2));
			}
			if (!ChessBoard::getBoardSquare(row + 1, column - 2)->getOccupied())
			{
				validMoves.push_back(Point(row + 1, column - 2));
			}
		}
		if (row + 2 < ChessBoard::rowMax && column + 1 < ChessBoard::columnMax && column - 1 > 0)
		{
			if (!ChessBoard::getBoardSquare(row + 2, column + 1)->getOccupied())
			{
				validMoves.push_back(Point(row + 2, column + 1));
			}
			if (!ChessBoard::getBoardSquare(row + 2, column - 1)->getOccupied())
			{
				validMoves.push_back(Point(row + 2, column - 1));
			}
		}
	}
	if (ChessBoard::validSquare(row - 2, column - 2)) {
		if (row - 1 > 0 && column + 2 < ChessBoard::columnMax && column - 2 > 0)
		{
			if (!ChessBoard::getBoardSquare(row - 1, column + 2)->getOccupied())
			{
				validMoves.push_back(Point(row - 1, column + 2));
			}
			if (!ChessBoard::getBoardSquare(row - 1, column - 2)->getOccupied())
			{
				validMoves.push_back(Point(row - 1, column - 2));
			}
		}
		if (row - 2 > 0 && column + 1 < ChessBoard::columnMax && column - 1 > 0)
		{
			if (!ChessBoard::getBoardSquare(row - 2, column + 1)->getOccupied())
			{
				validMoves.push_back(Point(row - 2, column + 1));
			}
			if (!ChessBoard::getBoardSquare(row - 2, column - 1)->getOccupied())
			{
				validMoves.push_back(Point(row - 2, column - 1));
			}
		}
	}
	return validMoves;
}
