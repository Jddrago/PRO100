#ifndef BOARDSQUARE_H_
#define BOARDSQUARE_H_

#include "ChessPiece.h"

class BoardSquare
{
public:
	BoardSquare();
	~BoardSquare();

public: // public methods
	ChessPiece getPiece();
	void setPiece(ChessPiece piece);

private: // private class members
	ChessPiece m_currentPiece;
};

#endif // !BOARDSQUARE_H_