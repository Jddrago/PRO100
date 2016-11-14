#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

#include <string>
#include <vector>
#include "Point.h"
#include "PieceType.h"

class ChessPiece
{
public:
	ChessPiece();
	ChessPiece(char color,char type);
	~ChessPiece();

public: // public methods
	char getPieceColor();
	void setPieceColor(char color);
	static std::string EnumToString(PieceType piece);
	char getPieceType();
	void setPieceType(char type);
	std::string toString();
	void clearMoveVector();
	virtual std::vector<Point> getMoves(int row, int column) = 0;

protected: // private class members
	char m_pieceColor ='\000';
	char m_PieceType = '\000';
	std::vector<Point> validMoves = std::vector<Point>();
	bool hasMoved = false;
	bool captured = false;
};

#endif // !CHESSPIECE_H_