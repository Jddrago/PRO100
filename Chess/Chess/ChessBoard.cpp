#include "ChessBoard.h"



ChessBoard::ChessBoard()
{
}


ChessBoard::~ChessBoard()
{
}

BoardSquare * ChessBoard::getBoard()
{
	return *board;
}

BoardSquare ChessBoard::getBoardSquare(int row, int column)
{
	return board[row][column];
}

void ChessBoard::setBoardSquare(int row, int column, BoardSquare square)
{
	board[row][column] = square;
}

void ChessBoard::initBoard()
{
	// todo initialize all board squares
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
