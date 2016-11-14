#ifndef PAWN_H_
#define PAWN_H_

#include "ChessPiece.h"
#include "ChessBoard.h"

class Pawn: public ChessPiece
{
public:
	Pawn();
	Pawn(char color, char type);
	~Pawn();

public:
	std::vector<Point> getMoves(int row, int column) override;
};

#endif // !PAWN_H_


