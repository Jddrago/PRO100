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
	std::vector<Point> enemyMoves;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1;  j <= 1 && ChessBoard::validSquare(row + i,column + j); j++)
		{
			if (ChessBoard::getBoardSquare(row + i, column + j)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + i, column + j));
			}
		}
	}
	return validMoves;
}

std::vector<Point> King::checkPath(int r1, int c1, int r2, int c2)
{
	return std::vector<Point>();
}

bool King::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	return false;
}
