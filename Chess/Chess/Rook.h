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
};

#endif // !ROOK_H_

