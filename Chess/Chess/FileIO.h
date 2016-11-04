#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include "GameLogger.h"

class FileIO
{
public:
	FileIO();
	~FileIO();

public:
	std::string ParsePlacement(std::string move);
	std::string ParseMove(std::string move);
	std::string ParseCastling(std::string move);
	void ParseGame();
	bool Parser(const char * const filename);

private:
	static std::ifstream m_moveStream;
};

#endif // !FILEIO_H_

