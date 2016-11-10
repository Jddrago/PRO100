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
	void getMoves(int row, int column);
};

#endif // !BISHOP_H_

