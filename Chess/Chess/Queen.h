#ifndef QUEEN_H_
#define QUEEN_H_

#include "ChessPiece.h"

class Queen: public ChessPiece
{
public:
	Queen();
	Queen(char color, char type);
	~Queen();

public:
	std::vector<Point> getMoves(int row, int column) override;
	bool canMoveAlongTrajectory(int r1, int c1, int r2, int c2) override;
};

#endif // !QUEEN_H_

