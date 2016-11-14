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
};

#endif // !KING_H_

