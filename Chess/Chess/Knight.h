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
	void getMoves(int row, int column);
};

#endif // !KNIGHT_H_

