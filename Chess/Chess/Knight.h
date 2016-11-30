#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "ChessPiece.h"

class Knight: public ChessPiece
{
public:
	Knight();
	Knight(char color, char type);
	~Knight();

public:
	std::vector<Point> getMoves(int row, int column) override;
	bool canMoveAlongTrajectory(int r1, int c1, int r2, int c2) override;
};

#endif // !KNIGHT_H_

