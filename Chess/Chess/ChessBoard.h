#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "BoardSquare.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

public: // public methods
	BoardSquare* getBoard(); // might need to edit
	BoardSquare getBoardSquare(int row, int column);
	void setBoardSquare(int row, int column, BoardSquare square);
	void initBoard();
	bool validMove(int r1, int c1, int r2, int c2);
	bool check();
	bool checkmate();

private: // private class members
	const static int rowMax = 8;
	const static int columnMax = 8;
	BoardSquare board[rowMax][columnMax];
};

#endif // !CHESSBOARD_H_