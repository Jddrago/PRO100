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

bool ChessBoard::validateMoves(int r1, int c1, int r2, int c2)
{
	ChessBoard::getBoardSquare(r1, c1)->getPiece()->clearMoveVector();
	bool validMove = false;
	std::vector<Point> possibleMoves = ChessBoard::getBoardSquare(r1, c1)->getPiece()->getMoves(r1, c1);
	for (unsigned int i = 0; i < possibleMoves.size(); i++)
	{
		if (possibleMoves.at(i).getPointX() == r2 && possibleMoves.at(i).getPointY() == c2) 
		{
			validMove = true;
		}
	}
	return validMove;
}

bool ChessBoard::validSquare(int row, int column)
{
	return (row >= 0 && row < rowMax) && (column >= 0 && column < columnMax);
}

bool ChessBoard::check(bool playerTurn)
{
	// based on bool check white or black king
	// get kings' location
	// compare location against all enemy pieces validmoves
	// if location is in an enemies validMoves return true
	return false;
}

bool ChessBoard::checkmate(bool playerTurn)
{
	// based on bool check white or black king
	// get kings' location
	// compare validMoves against all enemy pieces validmoves, remove any coordinates that match
	// compare location against all enemy pieces validmoves
	// if validMoves == 0location is in an enemies validMoves return true
	return false;
}
