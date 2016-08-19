#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

class ChessPiece
{
public:
	ChessPiece();
	~ChessPiece();

public: // public methods
	char getPieceType();
	void setPieceType(char pieceType);
	char getPieceColor();
	void setPieceColor(char color);

private: // private class members
	char m_pieceType;
	char m_pieceColor;
};

#endif // !CHESSPIECE_H_