#ifndef PAWN_H_
#define PAWN_H_

#include "ChessPiece.h"
#include "ChessBoard.h"

class Pawn: ChessPiece
{
public:
	Pawn();
	~Pawn();

public:
	void getMoves(int row, int column);
};

#endif // !PAWN_H_


