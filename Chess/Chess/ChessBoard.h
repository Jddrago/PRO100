#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "BoardSquare.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

private:
	const static int rowMax = 8;
	const static int columnMax = 8;
	BoardSquare board[rowMax][columnMax];
};

#endif // !CHESSBOARD_H_