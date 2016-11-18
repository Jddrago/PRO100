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
	for (int mod = 1; mod < ChessBoard::rowMax; mod++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (column - 1 < 0) {
				for (int j = 0; j <= 1 && ChessBoard::validSquare(row + (i * mod), column + (j * mod)); j++)
				{
					if (!ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getOccupied()) {
						validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
					}
					else
					{
						pieceDetected = true;
					}
				}
				pieceDetected = false;
			}
			else 
			{
				for (int j = -1; j <= 1 && ChessBoard::validSquare(row + (i * mod), column + (j * mod)); j++)
				{
					if (!ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getOccupied()) {
						validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
					}
					else
					{
						pieceDetected = true;
					}
				}
				pieceDetected = false;
			}
		}
	}
	return validMoves;
}
