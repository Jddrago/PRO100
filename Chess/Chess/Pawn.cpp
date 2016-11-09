#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(char color, char type)
{
	ChessPiece(color,type);
}


Pawn::~Pawn()
{
}

void Pawn::getMoves(int row, int column)
{
	validMoves.clear();
	if (m_pieceColor == 'l') 
	{
		if (hasMoved) 
		{
			validMoves.push_back(Point(row-1,column));
		}
		else 
		{
			validMoves.push_back(Point(row - 1, column));
			validMoves.push_back(Point(row - 2, column));
		}
	}
	else if (m_pieceColor == 'd') 
	{
		if (hasMoved)
		{
			validMoves.push_back(Point(row + 1, column));
		}
		else
		{
			validMoves.push_back(Point(row + 1, column));
			validMoves.push_back(Point(row + 2, column));
		}
	}
}
