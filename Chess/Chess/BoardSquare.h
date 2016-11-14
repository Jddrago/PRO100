#ifndef BOARDSQUARE_H_
#define BOARDSQUARE_H_

#include "ChessPiece.h"
#include "King.h"
#include <string>

class BoardSquare
{
public:
	BoardSquare();
	BoardSquare(ChessPiece* piece);
	BoardSquare(ChessPiece* piece, std::string backgroundColor);
	~BoardSquare();

public: // public methods
	ChessPiece* getPiece();
	void setPiece(ChessPiece* piece);
	std::string getBackgroundColor();
	void setBackgroundColor(std::string backgroundColor);
	bool getOccupied();
	void setOccupied(bool occupied);
	std::string toString();

private: // private class members
	ChessPiece* m_currentPiece = new King();
	std::string m_backgroundColor = "";
	bool m_isOccupied = false;
};

#endif // !BOARDSQUARE_H_