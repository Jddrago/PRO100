#ifndef BISHOP_H_
#define BISHOP_H_

#include "ChessPiece.h"

class Bishop: public ChessPiece
{
public:
	Bishop();
	Bishop(char color, char type);
	~Bishop();

public:
	std::vector<Point> getMoves(int row, int column) override;
	std::vector<Point> checkPath(int r1, int c1, int r2, int c2) override;
	bool canMoveAlongTrajectory(int r1, int c1, int r2, int c2) override;
};

#endif // !BISHOP_H_

