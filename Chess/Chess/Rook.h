#ifndef ROOK_H_
#define ROOK_H_

#include "ChessPiece.h"

class Rook: public ChessPiece
{
public:
	Rook();
	Rook(char color, char type);
	~Rook();

public:
	std::vector<Point> getMoves(int row, int column) override;
	std::vector<Point> checkPath(int r1, int c1, int r2, int c2) override;
	bool canMoveAlongTrajectory(int r1, int c1, int r2, int c2) override;
};

#endif // !ROOK_H_

