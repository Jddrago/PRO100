#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "BoardSquare.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

public: // public methods
	static BoardSquare* getBoardSquare(int row, int column);
	static void setBoardSquare(int row, int column, BoardSquare* square);
	static void initBoard();
	static bool validateMoves(int r1, int c1, int r2, int c2);
	static bool validSquare(int row, int column);
	static bool check(bool playerTurn);
	static bool checkmate(bool playerTurn, int row, int column);
	static bool canIntercept(bool playerTurn, int row, int column);

public:
	const static int rowMax = 8;
	const static int columnMax = 8;

private: // private class members
	static BoardSquare* board[rowMax][columnMax];

};

#endif // !CHESSBOARD_H_