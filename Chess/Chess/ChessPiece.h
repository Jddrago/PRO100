#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

#include <string>
#include <vector>

class ChessPiece
{
public:
	ChessPiece();
	~ChessPiece();

public: // public methods
	std::string getPieceType();
	void setPieceType(std::string pieceType);
	char getPieceColor();
	void setPieceColor(char color);
	virtual void getMoves(int row, int column);

public:
	enum Piece
	{
		KING,QUEEN,ROOK,KNIGHT,BISHOP,PAWN
	};

protected: // private class members
	std::string m_pieceType;
	char m_pieceColor;
	std::vector<int,int> validMoves;
	bool hasMoved = false;
};

#endif // !CHESSPIECE_H_