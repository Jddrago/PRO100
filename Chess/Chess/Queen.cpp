#include "Queen.h"
#include "ChessBoard.h"


Queen::Queen()
{
}

Queen::Queen(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Queen::~Queen()
{
}

std::vector<Point> Queen::getMoves(int row, int column)
{
	bool pieceDetected = false;
	for (int i = 1; (row + i < ChessBoard::rowMax) || (column + i < ChessBoard::columnMax) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row + i, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column + i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; (row + i < ChessBoard::rowMax) || (column + i < ChessBoard::columnMax) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row  -i, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row - i, column + i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; (row + i >= 0) || (column + i >= 0) && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row - i, column - i)->getOccupied())
		{
			validMoves.push_back(Point(row - i, column - i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; (row + i >= 0) || (column + i >= 0) && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row + i, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column - i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; row + i < ChessBoard::rowMax && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row + i, column)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; column + i < ChessBoard::columnMax && !pieceDetected; i++)
	{
		pieceDetected = false;
		if (!ChessBoard::getBoardSquare(row, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row, column + i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; row + i >= 0 && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row + i, column)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column));
		}
		else
		{
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; column + i >= 0 && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row, column + i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	return validMoves;
}
