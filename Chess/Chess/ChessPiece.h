#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

#include <string>
#include <vector>
#include "Point.h"

class ChessPiece
{
public:
	ChessPiece();
	~ChessPiece();

public: // public methods
	char getPieceColor();
	void setPieceColor(char color);
	virtual void availableMoves(int row, int column);

public:
	enum Piece
	{
		KING,QUEEN,ROOK,KNIGHT,BISHOP,PAWN
	};

protected: // private class members
	char m_pieceColor;
	std::vector<Point> validMoves;
	bool hasMoved = false;
	bool captured = false;
};

#endif // !CHESSPIECE_H_