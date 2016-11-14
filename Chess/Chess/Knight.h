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
};

#endif // !KNIGHT_H_

