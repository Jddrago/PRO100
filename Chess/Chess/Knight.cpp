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

bool Knight::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	bool canMove = false;
	if((r1-r2 == 1 || r1-r2 == -1) && (c1-c2 == -2 || c1-c2 == 2))
	{
		canMove = true;
	}
	else if((r1 - r2 == 2 || r1 - r2 == -2) && (c1 - c2 == -1 || c1 - c2 == 1))
	{
		canMove = true;
	}
	return canMove;
}
