#include "ChessBoard.h"

BoardSquare* ChessBoard::board[ChessBoard::rowMax][ChessBoard::columnMax];

ChessBoard::ChessBoard()
{
}


ChessBoard::~ChessBoard()
{
}

BoardSquare* ChessBoard::getBoardSquare(int row, int column)
{
	if (row <= rowMax && column <= columnMax)
	{
		return board[row][column];
	}
	return new BoardSquare();
}

void ChessBoard::setBoardSquare(int row, int column, BoardSquare* square)
{
	if (row <= rowMax && column <= columnMax)
	{
		board[row][column] = square;
	}
}

void ChessBoard::initBoard()
{
	for (int i = 0; i < rowMax; i++)
	{
		for (int j = 0; j < columnMax; j++)
		{
			board[i][j] = new BoardSquare();
		}
	}
}

bool ChessBoard::validMove(int r1, int c1, int r2, int c2)
{
	return false;
}

bool ChessBoard::check()
{
	return false;
}

bool ChessBoard::checkmate()
{
	return false;
}
