#ifndef KING_H_
#define KING_H_

#include "ChessPiece.h"

class King: public ChessPiece
{
public:
	King();
	King(char color, char type);
	~King();

public:
	std::vector<Point> getMoves(int row, int column) override;
	bool canMoveAlongTrajectory(int r1, int c1, int r2, int c2) override;
};

#endif // !KING_H_

