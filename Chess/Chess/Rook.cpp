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

bool Rook::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	//check polarity of row and column to determin the trajectory
	//get all moves along that path
	bool canMove = false;
	if (c2 - c1 == 0 && (r2 > 0 || r2 > 0))
	{
		canMove = true;
	}
	else if (r2 - r1 == 0 && (c2 > 0 || c2 < 0))
	{
		canMove = true;
	}
	return canMove;
}
