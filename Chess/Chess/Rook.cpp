#include "Rook.h"
#include "ChessBoard.h"


Rook::Rook()
{
}

Rook::Rook(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Rook::~Rook()
{
}

std::vector<Point> Rook::getMoves(int row, int column)
{
	bool pieceDetected = false;
	for (int i = 1; row + i < ChessBoard::rowMax && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row + i, column)->getOccupied()) {
			validMoves.push_back(Point(row + i, column));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row + i, column)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + i, column));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = 1; column + i < ChessBoard::columnMax && !pieceDetected; i++)
	{
		if (!ChessBoard::getBoardSquare(row, column + i)->getOccupied()) {
			validMoves.push_back(Point(row, column + i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row, column + i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row, column + i));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; row + i >= 0 && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row + i, column)->getOccupied()) {
			validMoves.push_back(Point(row + i, column));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row + i, column)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row + i, column));
			}
			pieceDetected = true;
		}
	}
	pieceDetected = false;
	for (int i = -1; column + i >= 0 && !pieceDetected; i--)
	{
		if (!ChessBoard::getBoardSquare(row, column + i)->getOccupied()) {
			validMoves.push_back(Point(row, column + i));
		}
		else
		{
			if (ChessBoard::getBoardSquare(row, column + i)->getPiece()->getPieceColor() != this->getPieceColor())
			{
				validMoves.push_back(Point(row, column + i));
			}
			pieceDetected = true;
		}
	}
	return validMoves;
}

std::vector<Point> Rook::checkPath(int r1, int c1, int r2, int c2)
{
	int loopMod = 1;
	if (r1 - r2 == 0 && c1 - c2 > 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1, c1 - i) && c1 - i != c2; i++)
		{
			validMoves.push_back(Point(r1, c1 - i));
			loopMod = i + 1;
		}
		if (r1 == r2 && c1 - loopMod == c2)
		{
			validMoves.push_back(Point(r2, c2));
			if (ChessBoard::validSquare(r2, c2 - 1)) 
			{
				if (!ChessBoard::getBoardSquare(r2, c2 - 1)->getOccupied()) 
				{
					validMoves.push_back(Point(r2, c2 - 1));
				}
			}
		}
	}
	else if (r1 - r2 == 0 && c1 - c2 < 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1, c1 + i) && c1 + i != c2; i++)
		{
			validMoves.push_back(Point(r1, c1 + i));
			loopMod = i + 1;
		}
		if (r1 == r2 && c1 + loopMod == c2)
		{
			validMoves.push_back(Point(r2, c2));
			if (ChessBoard::validSquare(r2, c2 + 1))
			{
				if (!ChessBoard::getBoardSquare(r2, c2 + 1)->getOccupied())
				{
					validMoves.push_back(Point(r2, c2 + 1));
				}
			}
		}
	}
	else if (r1 - r2 > 0 && c1 - c2 == 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 - i, c1) && r1 - i != r2; i++)
		{
			validMoves.push_back(Point(r1 - i, c1));
			loopMod = i + 1;
		}
		if (r1 - loopMod == r2 && c1 == c2)
		{
			validMoves.push_back(Point(r2, c2));
			if (ChessBoard::validSquare(r2 - 1, c2))
			{
				if (!ChessBoard::getBoardSquare(r2 - 1, c2)->getOccupied())
				{
					validMoves.push_back(Point(r2 - 1, c2));
				}
			}
		}
	}
	else if (r1 - r2 < 0 && c1 - c2 == 0)
	{
		for (int i = 1; ChessBoard::validSquare(r1 + i, c1) && r1 + i != r2; i++)
		{
			validMoves.push_back(Point(r1 + i, c1));
			loopMod = i + 1;
		}
		if (r1 + loopMod == r2 && c1 == c2)
		{
			validMoves.push_back(Point(r2, c2));
			if (ChessBoard::validSquare(r2 + 1, c2))
			{
				if (!ChessBoard::getBoardSquare(r2 + 1, c2)->getOccupied())
				{
					validMoves.push_back(Point(r2 + 1, c2));
				}
			}
		}
	}
	return validMoves;
}

bool Rook::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	//check polarity of row and column to determin the trajectory
	//get all moves along that path
	bool canMove = false;
	if (c2 - c1 == 0 && (r2 > 0 || r2 > 0) && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	else if (r2 - r1 == 0 && (c2 > 0 || c2 < 0) && ChessBoard::validateMoves(r1, c1, r2, c2))
	{
		canMove = true;
	}
	return canMove;
}
