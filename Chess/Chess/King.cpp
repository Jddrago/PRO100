#include "King.h"
#include "ChessBoard.h"



King::King()
{
}

King::King(char color, char type)
{
	ChessPiece(color,type);
}


King::~King()
{
}

void King::getMoves(int row, int column)
{
	validMoves.clear();
	if (row == 0 && column == 0) 
	{
		if(!ChessBoard::getBoardSquare(row,column+1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1)); 
		}
		validMoves.push_back(Point(row + 1, column + 1));
		validMoves.push_back(Point(row + 1, column));
	}
	else if (row == ChessBoard::rowMax-1 && column == ChessBoard::columnMax-1)
	{
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row - 1, column - 1));
		validMoves.push_back(Point(row - 1, column));
	}
	else if (row == 0 && column == ChessBoard::columnMax-1)
	{
		validMoves.push_back(Point(row, column + 1));
		validMoves.push_back(Point(row - 1, column + 1));
		validMoves.push_back(Point(row - 1, column));
	}
	else if (row == ChessBoard::rowMax - 1 && column == 0)
	{
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row + 1, column - 1));
		validMoves.push_back(Point(row + 1, column));
	}
	else if (row == 0) 
	{
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row, column + 1));
		validMoves.push_back(Point(row - 1, column + 1));
		validMoves.push_back(Point(row - 1, column));
		validMoves.push_back(Point(row - 1, column - 1));
	}
	else if (row == ChessBoard::rowMax-1)
	{
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row, column + 1));
		validMoves.push_back(Point(row + 1, column + 1));
		validMoves.push_back(Point(row + 1, column));
		validMoves.push_back(Point(row + 1, column - 1));
	}
	else if (column == 0)
	{
		validMoves.push_back(Point(row + 1, column + 1));
		validMoves.push_back(Point(row, column + 1));
		validMoves.push_back(Point(row - 1, column + 1));
		validMoves.push_back(Point(row + 1, column));
		validMoves.push_back(Point(row - 1, column));
	}
	else if (row == ChessBoard::columnMax - 1)
	{
		validMoves.push_back(Point(row + 1, column - 1));
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row - 1, column - 1));
		validMoves.push_back(Point(row + 1, column));
		validMoves.push_back(Point(row - 1, column));
	}
	else 
	{
		validMoves.push_back(Point(row - 1, column - 1));
		validMoves.push_back(Point(row, column - 1));
		validMoves.push_back(Point(row - 1, column+1));
		validMoves.push_back(Point(row, column + 1));
		validMoves.push_back(Point(row + 1, column + 1));
		validMoves.push_back(Point(row + 1, column));
		validMoves.push_back(Point(row-1, column - 1));
		validMoves.push_back(Point(row -1, column));
	}
}
