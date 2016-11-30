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
