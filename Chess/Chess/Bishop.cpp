#include "Bishop.h"
#include "ChessBoard.h"


Bishop::Bishop()
{
}

Bishop::Bishop(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Bishop::~Bishop()
{
}

std::vector<Point> Bishop::getMoves(int row, int column)
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
		if (!ChessBoard::getBoardSquare(row - i, column + i)->getOccupied())
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
		if (!ChessBoard::getBoardSquare(row + i, column - i)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column - i));
		}
		else
		{
			pieceDetected = true;
		}
	}
	return validMoves;
}
