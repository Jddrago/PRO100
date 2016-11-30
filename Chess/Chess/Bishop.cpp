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
	for (int i = 1; ChessBoard::validSquare(row + i,column + i) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row + i, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column + i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row + i, column + i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + i, column + i));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; ChessBoard::validSquare(row - i, column + i) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row - i, column + i)->getOccupied())
		{
			validMoves.push_back(Point(row - i, column + i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row - i, column + i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row - i, column + i));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; ChessBoard::validSquare(row - i, column - i) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row - i, column - i)->getOccupied())
		{
			validMoves.push_back(Point(row - i, column - i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row - i, column - i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row - i, column - i));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; ChessBoard::validSquare(row + i, column - i) && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row + i, column - i)->getOccupied())
		{
			validMoves.push_back(Point(row + i, column - i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row + i, column - i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + i, column - i));
			}
			pieceDetected = true;
		}
	}
	return validMoves;
}

std::vector<Point> Bishop::checkPath(int r1, int c1, int r2, int c2)
{
	if (r1 - r2 > 0 && c1 - c2 > 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 + i, c1 + i) && c1 + i != c2 && r1 + i != r2; i++)
		{
			validMoves.push_back(Point(r1 + i, c1 + i));
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 < 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 - i, c1 - i) && c1 - i != c2 && r1 - i != r2; i++)
		{
			validMoves.push_back(Point(r1 - i, c1 - i));
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 > 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 - i, c1 + i) && c1 + i != c2 && r1 - i != r2; i++)
		{
			validMoves.push_back(Point(r1 - i, c1 + i));
		}
	}
	else if (r1 - r2 > 0 && c1 - c2 < 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 + i, c1 - i) && c1 - i != c2 && r1 + i != r2; i++)
		{
			validMoves.push_back(Point(r1 + i, c1 - i));
		}
	}
	return validMoves;
}

bool Bishop::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	bool canMove = false;
	if (r1 - r2 == c1 - c2 && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	else if (r1 - r2 == -(c1 - c2) || -(r1 - r2) == c1 - c2 && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	return canMove;
}
