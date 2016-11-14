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
};

#endif // !BISHOP_H_

