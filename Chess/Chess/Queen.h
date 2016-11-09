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
	void getMoves(int row, int column);
};

#endif // !QUEEN_H_

