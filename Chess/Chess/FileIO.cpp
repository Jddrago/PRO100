#include "FileIO.h"
#include "ChessPiece.h"
#include <ctype.h>

std::ifstream FileIO::m_moveStream;

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

std::string FileIO::ParsePlacement(std::string move)
{
	const std::locale loc;
	std::string piecetype,pieceColor,locationP1,locationP2;
	switch (std::toupper(move.at(0), loc))
	{
	case 'K':
		piecetype = ChessPiece::EnumToString(PieceType::KING);
		break;
	case 'Q':
		piecetype = ChessPiece::EnumToString(PieceType::QUEEN);
		break;
	case 'R':
		piecetype = ChessPiece::EnumToString(PieceType::ROOK);
		break;
	case 'N':
		piecetype = ChessPiece::EnumToString(PieceType::KNIGHT);
		break;
	case 'P':
		piecetype = ChessPiece::EnumToString(PieceType::PAWN);
		break;
	case 'B':
		piecetype = ChessPiece::EnumToString(PieceType::BISHOP);
		break;
	default:
		piecetype = "Unknown piece";
		break;
	}
	switch (move.at(1))
	{
	case 'l':
		pieceColor = "Light";
		break;
	case 'd':
		pieceColor = "Dark";
		break;
	default:
		break;
	}
	if (move[2] >= 'a' && move[2] <= 'h') 
	{
		locationP1 = move[2];
	}
	if (move[3] >= '1' && move[3] <= '8') 
	{
		locationP2 = move[3];
	}
	//GameLogger::Log("%s:Placed %s %s at %s%s",GameLogger::EnumToString(LogMsgType::Info), pieceColor, piecetype, locationP1, locationP2);
	return "Placed " + pieceColor + " " + piecetype + " at " + locationP1 + locationP2;
}

std::string FileIO::ParseMove(std::string move)
{
	std::string locationP1, locationP2, locationP3, locationP4;
	if (move[0] >= 'a' && move[0] <= 'h')
	{
		locationP1 = move[0];
	}
	if (move[1] >= '1' && move[1] <= '8')
	{
		locationP2 = move[1];
	}
	if (move[3] >= 'a' && move[3] <= 'h')
	{
		locationP3 = move[3];
	}
	if (move[4] >= '1' && move[4] <= '8')
	{
		locationP4 = move[4];
	}
	return "Moved piece at " + locationP1 + locationP2 + " to " + locationP3 + locationP4;
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
