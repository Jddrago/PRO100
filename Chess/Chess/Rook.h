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
	void getMoves(int row, int column);
};

#endif // !ROOK_H_

