#include "FileIO.h"
#include "ChessPiece.h"
#include <ctype.h>
#include "ChessBoard.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"

std::ifstream FileIO::m_moveStream;

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

std::string FileIO::ParsePlacement(std::string move)
{
	std::locale loc = std::locale();
	std::string piecetype,pieceColor,locationP1,locationP2;
	ChessPiece* piece;
	switch (std::toupper(move.at(0), loc))
	{
	case 'K':
		piecetype = ChessPiece::EnumToString(PieceType::KING);
		piece = new King();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	case 'Q':
		piecetype = ChessPiece::EnumToString(PieceType::QUEEN);
		piece = new Queen();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	case 'R':
		piecetype = ChessPiece::EnumToString(PieceType::ROOK);
		piece = new Rook();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	case 'N':
		piecetype = ChessPiece::EnumToString(PieceType::KNIGHT);
		piece = new Knight();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	case 'P':
		piecetype = ChessPiece::EnumToString(PieceType::PAWN);
		piece = new Pawn();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	case 'B':
		piecetype = ChessPiece::EnumToString(PieceType::BISHOP);
		piece = new Bishop();
		piece->setPieceType(std::toupper(move.at(0), loc));
		break;
	default:
		piecetype = "Unknown piece";
		break;
	}
	switch (move.at(1))
	{
	case 'l':
		pieceColor = "Light";
		piece->setPieceColor(move.at(1));
		break;
	case 'd':
		pieceColor = "Dark";
		piece->setPieceColor(move.at(1));
		break;
	default:
		break;
	}
	locationP1 = std::toupper(move.at(2), loc);
	locationP2 = move.at(3);
	//GameLogger::Log("%s:Placed %s\n",GameLogger::EnumToString(LogMsgType::Info), move);
	if (!ChessBoard::getBoardSquare((move.at(3) - '0'-1), (move.at(2) - 'a'))->getOccupied()) 
	{
		ChessBoard::setBoardSquare((move.at(3) - '0' - 1), (move.at(2) - 'a'),new BoardSquare(piece));
		ChessBoard::getBoardSquare((move.at(3) - '0' - 1), (move.at(2) - 'a'))->setOccupied(true);
	}
	return "Placed " + pieceColor + " " + piecetype + " at " + std::toupper(move.at(2), loc) + move.at(3);
}

std::string FileIO::ParseMove(std::string move)
{
	if (ChessBoard::validateMoves((move.at(1) - '0' - 1), (move.at(0) - 'a'), (move.at(4) - '0' - 1), (move.at(3) - 'a')))
	{
		ChessBoard::setBoardSquare((move.at(4) - '0' - 1), (move.at(3) - 'a'), ChessBoard::getBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a')));
		ChessBoard::setBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a'), new BoardSquare());
		return "Moved piece at " + move.substr(0, 2) + " to " + move.substr(3, 2);
	}
	else 
	{
		return "Invalid move";
	}
}

std::string FileIO::ParseCastling(std::string move)
{
	return "Moved piece at " + move.substr(0, 2) + " to " + move.substr(3, 2) + " and moved piece at " + move.substr(6, 2) + " to " + move.substr(9, 2);
}

bool FileIO::Parser(const char * const filename)
{
	m_moveStream.open(filename, std::ios_base::in);
	if (!m_moveStream.is_open()) 
	{
		GameLogger::Log("%s MoveReader::Initialize() failed. Unable to open file [%s]", GameLogger::EnumToString(LogMsgType::FatalError), filename);
		return false;
	}
	else 
	{
		GameLogger::Log("%s ConfigReader::Initialize() opened file [%s] for reading\n", GameLogger::EnumToString(LogMsgType::Process), filename);
		return true;
	}
}

void FileIO::ParseGame()
{
	char fileLine[256];
	while (!m_moveStream.eof()) 
	{
		m_moveStream.getline(fileLine,256);
		if (std::regex_match(fileLine, std::regex("[KQBNRP][ld][a-h][1-8]"))) 
		{
			std::cout << fileLine << std::endl;
			std::cout << ParsePlacement(fileLine) << std::endl;
		}
		else if (std::regex_match(fileLine, std::regex("[a-h][1-8]\\s[a-h][1-8]"))) 
		{
			std::cout << fileLine << std::endl;
			std::cout << ParseMove(fileLine) << std::endl;
		}
		else if (std::regex_match(fileLine, std::regex("[a-h][1-8]\\s[a-h][1-8]\\s[a-h][1-8]\\s[a-h][1-8]"))) 
		{
			std::cout << fileLine << std::endl;
			std::cout << ParseCastling(fileLine) << std::endl;
		}
	}
	m_moveStream.close();
}
