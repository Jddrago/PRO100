#include "King.h"
#include "ChessBoard.h"



King::King()
{
}

King::King(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


King::~King()
{
}

std::vector<Point> King::getMoves(int row, int column)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1;  j <= 1 && ChessBoard::validSquare(row + i,column + j); j++)
		{
			if (!ChessBoard::getBoardSquare(row + i, column + j)->getOccupied()) 
			{
				validMoves.push_back(Point(row + i, column + j));
			}
		}

	}
	return validMoves;
}
