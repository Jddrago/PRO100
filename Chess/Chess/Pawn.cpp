#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color, char type)
{
	setPieceColor(color);
	setPieceType(type);
}


Pawn::~Pawn()
{
}

std::vector<Point> Pawn::getMoves(int row, int column)
{
	if (m_pieceColor == 'd') 
	{
		if (hasMoved) 
		{
			if (ChessBoard::validSquare(row - 1, column))
			{
				if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
				{
					validMoves.push_back(Point(row - 1, column));
				}
			}
			if (ChessBoard::validSquare(row - 1, column - 1)) 
			{
				if (ChessBoard::getBoardSquare(row - 1, column - 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row - 1, column - 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row - 1, column - 1));
				}
			}
			if (ChessBoard::validSquare(row - 1, column + 1))
			{
				if (ChessBoard::getBoardSquare(row - 1, column + 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row - 1, column + 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row - 1, column + 1));
				}
			}
		}
		else 
		{
			if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row - 1, column));
			}
			if (!ChessBoard::getBoardSquare(row - 2, column)->getOccupied())
			{
				validMoves.push_back(Point(row - 2, column));
			}
			if (ChessBoard::validSquare(row - 1, column - 1))
			{
				if (ChessBoard::getBoardSquare(row - 1, column - 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row - 1, column - 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row - 1, column - 1));
				}
			}
			if (ChessBoard::validSquare(row - 1, column + 1))
			{
				if (ChessBoard::getBoardSquare(row - 1, column + 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row - 1, column + 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row - 1, column + 1));
				}
			}
		}
	}
	else if (m_pieceColor == 'l') 
	{
		if (hasMoved)
		{
			if (ChessBoard::validSquare(row + 1, column))
			{
				if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
				{
					validMoves.push_back(Point(row + 1, column));
				}
			}
			if (ChessBoard::validSquare(row + 1, column - 1))
			{
				if (ChessBoard::getBoardSquare(row + 1, column - 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row + 1, column - 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row + 1, column - 1));
				}
			}
			if (ChessBoard::validSquare(row + 1, column + 1))
			{
				if (ChessBoard::getBoardSquare(row + 1, column + 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row + 1, column + 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row + 1, column + 1));
				}
			}
		}
		else
		{
			if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
			{
				validMoves.push_back(Point(row + 1, column));
			}
			if (!ChessBoard::getBoardSquare(row + 2, column)->getOccupied())
			{
				validMoves.push_back(Point(row + 2, column));
			}
			if (ChessBoard::validSquare(row + 1, column - 1))
			{
				if (ChessBoard::getBoardSquare(row + 1, column - 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row + 1, column - 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row + 1, column - 1));
				}
			}
			if (ChessBoard::validSquare(row + 1, column + 1))
			{
				if (ChessBoard::getBoardSquare(row + 1, column + 1)->getPiece()->getPieceColor() != this->getPieceColor() && ChessBoard::getBoardSquare(row + 1, column + 1)->getPiece()->getPieceColor() != '\000')
				{
					validMoves.push_back(Point(row + 1, column + 1));
				}
			}
		}
	}
	return validMoves;
}

std::vector<Point> Pawn::checkPath(int r1, int c1, int r2, int c2)
{
	return std::vector<Point>();
}

bool Pawn::canMoveAlongTrajectory(int r1, int c1, int r2, int c2)
{
	bool canMove = false;
	if (ChessBoard::getBoardSquare(r1, c1)->getPiece()->getPieceColor() == 'l') 
	{
		if (!hasMoved) {
			if ((r1 - r2 == 1 || r1 - r2 == 2) && c1 - c2 == 0 && ChessBoard::validateMoves(r1,c1,r2,c2))
			{
				canMove = true;
			}
		}
		else
		{
			if (r1 - r2 == 1 && c1 - c2 == 0 && ChessBoard::validateMoves(r1, c1, r2, c2))
			{
				canMove = true;
			}
		}
	}
	else if (ChessBoard::getBoardSquare(r1, c1)->getPiece()->getPieceColor() == 'd')
	{
		if (!hasMoved) {
			if ((r1 - r2 == -1 || r1 - r2 == -2) && c1 - c2 == 0 && ChessBoard::validateMoves(r1, c1, r2, c2))
			{
				canMove = true;
			}
		}
		else
		{
			if (r1 - r2 == -1 && c1 - c2 == 0 && ChessBoard::validateMoves(r1, c1, r2, c2))
			{
				canMove = true;
			}
		}
	}
	return canMove;
}
