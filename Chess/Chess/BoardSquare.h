#ifndef BOARDSQUARE_H_
#define BOARDSQUARE_H_

#include "ChessPiece.h"
#include <string>

class BoardSquare
{
public:
	BoardSquare();
	BoardSquare(ChessPiece piece);
	BoardSquare(ChessPiece piece, std::string backgroundColor);
	~BoardSquare();

public: // public methods
	ChessPiece getPiece();
	void setPiece(ChessPiece piece);
	std::string getBackgroundColor();
	void setBackgroundColor(std::string backgroundColor);
	bool getOccupied();
	void setOccupied(bool occupied);

private: // private class members
	ChessPiece m_currentPiece;
	std::string m_backgroundColor;
	bool m_isOccupied = false;
};

#endif // !BOARDSQUARE_H_