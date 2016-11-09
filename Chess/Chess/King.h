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
	void getMoves(int row, int column);
};

#endif // !KING_H_

