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
};

#endif // !QUEEN_H_

