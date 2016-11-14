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
	if (row == 0 && column == 0) 
	{
		if(!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1)); 
		}
		if (!ChessBoard::getBoardSquare(row + 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column));
		}
	}
	else if (row == ChessBoard::rowMax-1 && column == ChessBoard::columnMax-1)
	{
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
	}
	else if (row == 0 && column == ChessBoard::columnMax-1)
	{
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
	}
	else if (row == ChessBoard::rowMax - 1 && column == 0)
	{
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column - 1));
		}		
		if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column));
		}
	}
	else if (row == 0) 
	{
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column - 1));
		}
	}
	else if (row == ChessBoard::rowMax-1)
	{
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column - 1));
		}
	}
	else if (column == 0)
	{
		if (!ChessBoard::getBoardSquare(row + 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
	}
	else if (column == ChessBoard::columnMax - 1)
	{
		if (!ChessBoard::getBoardSquare(row + 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
	}
	else 
	{
		if (!ChessBoard::getBoardSquare(row - 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column + 1)->getOccupied())
		{
			validMoves.push_back(Point(row + 1, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row + 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row, column + 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column - 1)->getOccupied())
		{
			validMoves.push_back(Point(row, column - 1));
		}
		if (!ChessBoard::getBoardSquare(row - 1, column)->getOccupied())
		{
			validMoves.push_back(Point(row - 1, column));
		}
	}
	return validMoves;
}
