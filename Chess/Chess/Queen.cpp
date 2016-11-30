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
	if (column - 1 < 0) {
		for (int i = -1; i <= 1; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				for (int mod = 1; mod < ChessBoard::rowMax && ChessBoard::validSquare(row + (i * mod), column + (j * mod)) && !pieceDetected; mod++)
				{
					if (!ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getOccupied()) {
						validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
					}
					else
					{
						if (ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getPiece()->getPieceColor() != this->getPieceColor())
						{
							validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
						}
						pieceDetected = true;
					}
				}
				pieceDetected = false;
			}
		}
	}
		else
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					for (int mod = 1; mod < ChessBoard::rowMax && ChessBoard::validSquare(row + (i * mod), column + (j * mod)) && !pieceDetected; mod++)
					{
						if (!ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getOccupied()) {
							validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
						}
						else
						{
							if (ChessBoard::getBoardSquare(row + (i * mod), column + (j * mod))->getPiece()->getPieceColor() != this->getPieceColor())
							{
								validMoves.push_back(Point(row + (i * mod), column + (j * mod)));
							}
							pieceDetected = true;
						}
					}
					pieceDetected = false;
				}
			}
		}
	return validMoves;
}

std::vector<Point> Queen::checkPath(int r1, int c1, int r2, int c2)
{
	if (r1 - r2 > 0 && c1 - c2 > 0)
	{
		for(int i = 1; ChessBoard::validSquare(r1 + i, c1 + i) && c1 + i != c2 && r1 + i != r2;i++)
		{
			validMoves.push_back(Point(r1 + i,c1 + i));
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 < 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1 - i, c1 - i) && c1 - i != c2 && r1 - i != r2; i++)
		{
			validMoves.push_back(Point(r1 - i, c1 - i));
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 > 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1 - i, c1 + i) && c1 + i != c2 && r1 - i != r2; i++)
		{
			validMoves.push_back(Point(r1 - i, c1 + i));
		}
	}
	else if (r1 - r2 > 0 && c1 - c2 < 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1 + i, c1 - i) && c1 - i != c2 && r1 + i != r2; i++)
		{
			validMoves.push_back(Point(r1 + i, c1 - i));
		}
	}
	else if (r1 - r2 == 0 && c1 - c2 > 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1, c1 + i) && c1 + i != c2; i++)
		{
			validMoves.push_back(Point(r1, c1 + i));
		}
	}
	else if (r1 - r2 == 0 && c1 - c2 < 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1, c1 - i) && c1 - i != c2; i++)
		{
			validMoves.push_back(Point(r1, c1 - i));
		}
	}
	else if (r1 - r2 > 0 && c1 - c2 == 0)
	{
		for (int i = 1;ChessBoard::validSquare(r1-i,c1) && r1-i !=r2; i++)
		{
			validMoves.push_back(Point(r1-i, c1));
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 == 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 - i, c1) && r1 + i != r2; i++)
		{
			validMoves.push_back(Point(r1+i, c1));
		}
	}
	return validMoves;
}

bool Queen::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
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
	else if (c2 - c1 == 0 && (r2 > 0 || r2 > 0) && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	else if (r2 - r1 == 0 && (c2 > 0 || c2 < 0) && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	return canMove;
}
