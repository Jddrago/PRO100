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
	std::vector<Point> enemyMoves;
	int kingRow = -1,kingColumn = -1;

	// based on bool check white or black king
	// get kings' location
	// compare location against all enemy pieces validmoves
	// if location is in an enemies validMoves return true
	if (playerTurn) 
	{
		for (int i = 0; i < rowMax; i++)
		{
			for (int j = 0; j < columnMax; j++)
			{
				if (board[i][j]->getPiece()->getPieceType() == 'K') 
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'l')
					{
						kingRow = i;
						kingColumn = j;
					}
				}
			}
		}
		for (int i = 0; i < rowMax; i++)
		{
			for (int j = 0; j < columnMax; j++)
			{
				if (board[i][j]->getPiece()->getPieceColor() == 'd')
				{
					board[i][j]->getPiece()->clearMoveVector();
					enemyMoves = board[i][j]->getPiece()->getMoves(i,j);
					for (unsigned int p = 0; p < enemyMoves.size(); p++)
					{
						if (enemyMoves.at(p).getPointX() == kingRow && enemyMoves.at(p).getPointY() == kingColumn) 
						{
							return true;
						}
					}
				}	
			}
		}
	}
	else
	{
		for (int i = 0; i < rowMax; i++)
		{
			for (int j = 0; j < columnMax; j++)
			{
				if (board[i][j]->getPiece()->getPieceType() == 'K')
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'd')
					{
						kingRow = i;
						kingColumn = j;
					}
				}
			}
		}
		for (int i = 0; i < rowMax; i++)
		{
			for (int j = 0; j < columnMax; j++)
			{
				if (board[i][j]->getPiece()->getPieceColor() == 'l')
				{
					board[i][j]->getPiece()->clearMoveVector();
					enemyMoves = board[i][j]->getPiece()->getMoves(i, j);
					for (unsigned int p = 0; p < enemyMoves.size(); p++)
					{
						if (enemyMoves.at(p).getPointX() == kingRow && enemyMoves.at(p).getPointY() == kingColumn)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool ChessBoard::checkmate(bool playerTurn, int row, int column)
{
	std::vector<Point> enemyMoves;
	std::vector<Point> kingsMoves;
	int kingRow = -1, kingColumn = -1;
	// based on bool check white or black king
	// get kings' location
	// compare location against all enemy pieces validmoves
	// compare validMoves against all enemy pieces validmoves, remove any coordinates that match
	// if validMoves == 0 && location is in an enemies validMoves return true
	bool inCheck = check(playerTurn);
	if (inCheck) {
		if (playerTurn)
		{
			for (int i = 0; i < rowMax; i++)
			{
				for (int j = 0; j < columnMax; j++)
				{
					if (board[i][j]->getPiece()->getPieceType() == 'K')
					{
						if (board[i][j]->getPiece()->getPieceColor() == 'l')
						{
							board[i][j]->getPiece()->clearMoveVector();
							kingsMoves = board[i][j]->getPiece()->getMoves(i, j);
							kingRow = i;
							kingColumn = j;
						}
					}
				}
			}
			for (int i = 0; i < rowMax; i++)
			{
				for (int j = 0; j < columnMax; j++)
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'd')
					{
						board[i][j]->getPiece()->clearMoveVector();
						enemyMoves = board[i][j]->getPiece()->getMoves(i, j);
						for (unsigned int k = 0; k < kingsMoves.size(); k++) {
							for (unsigned int p = 0; p < enemyMoves.size() && kingsMoves.size() != 0; p++)
							{
								if (enemyMoves.at(p).getPointX() == kingsMoves.at(k).getPointX() && enemyMoves.at(p).getPointY() == kingsMoves.at(k).getPointY())
								{
									kingsMoves.erase(kingsMoves.begin() + k);
								}
							}
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < rowMax; i++)
			{
				for (int j = 0; j < columnMax; j++)
				{
					if (board[i][j]->getPiece()->getPieceType() == 'K')
					{
						if (board[i][j]->getPiece()->getPieceColor() == 'd')
						{
							board[i][j]->getPiece()->clearMoveVector();
							kingsMoves = board[i][j]->getPiece()->getMoves(i, j);
							kingRow = i;
							kingColumn = j;
						}
					}
				}
			}
			for (int i = 0; i < rowMax; i++)
			{
				for (int j = 0; j < columnMax; j++)
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'l')
					{
						board[i][j]->getPiece()->clearMoveVector();
						enemyMoves = board[i][j]->getPiece()->getMoves(i, j);
						for (unsigned int k = 0; k < kingsMoves.size(); k++) {
							for (unsigned int p = 0; p < enemyMoves.size() && k < kingsMoves.size(); p++)
							{
								if (enemyMoves.at(p).getPointX() == kingsMoves.at(k).getPointX() && enemyMoves.at(p).getPointY() == kingsMoves.at(k).getPointY())
								{
									kingsMoves.erase(kingsMoves.begin() + k);
								}
							}
						}
					}
				}
			}
		}
	}
	if (inCheck && kingsMoves.size() == 0 && !canIntercept(playerTurn, row, column,kingRow,kingColumn))
	{
		return true;
	}
	return false;
}

bool ChessBoard::canIntercept(bool playerTurn, int row, int column, int kingRow, int kingColumn)
{
	board[row][column]->getPiece()->clearMoveVector();
	std::vector<Point> enemyMoves = board[row][column]->getPiece()->checkPath(row,column,kingRow,kingColumn);
	bool canIntercept = false;
	if (playerTurn)
	{
		for (int i = 0; i < rowMax && !canIntercept; i++)
		{
			for (int j = 0; j < columnMax && !canIntercept; j++)
			{
				if (board[i][j]->getPiece()->getPieceType() != 'K')
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'l')
					{
						for (unsigned int p = 0; p < enemyMoves.size() && !canIntercept; p++)
						{
							canIntercept = board[i][j]->getPiece()->canMoveAlongTrajectory(i, j, enemyMoves.at(p).getPointX(), enemyMoves.at(p).getPointY());
						}
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < rowMax && !canIntercept; i++)
		{
			for (int j = 0; j < columnMax && !canIntercept; j++)
			{
				if (board[i][j]->getPiece()->getPieceType() != 'K')
				{
					if (board[i][j]->getPiece()->getPieceColor() == 'd')
					{
						for (unsigned int p = 0; p < enemyMoves.size() && !canIntercept; p++)
						{
							canIntercept = board[i][j]->getPiece()->canMoveAlongTrajectory(i, j, enemyMoves.at(p).getPointX(), enemyMoves.at(p).getPointY());
						}
					}
				}
			}
		}
	}
	return canIntercept;
}
