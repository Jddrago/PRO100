#include "ChessBoard.h"
#include <iostream>
#include "FileIO.h"

int main(int argc, char** argv) 
{
	FileIO fileReader;
	GameLogger::Initialize("..\\Logs\\","Chess.log");
	fileReader.Parser(argv[1]);
	fileReader.ParseGame();
	fileReader.Parser(argv[2]);
	fileReader.ParseGame();
	return 0;
}