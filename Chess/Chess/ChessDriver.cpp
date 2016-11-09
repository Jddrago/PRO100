#include "ChessBoard.h"
#include <iostream>
#include "FileIO.h"

int main(int argc, char** argv) 
{
	ChessBoard::initBoard();
	FileIO fileReader;
	if (!GameLogger::Initialize("..\\Logs\\","Chess.log")) return -1;
	if (!fileReader.Parser("..\\Data\\Placement.txt")) return -1;
	fileReader.ParseGame();
	//if (!fileReader.Parser("..\\Data\\MoveTests.txt")) return -1;
	//fileReader.ParseGame();

	std::cout << "  A  B  C  D  E  F  G  H " << std::endl;
	for (int i = 0; i < ChessBoard::rowMax; i++)
	{
		std::cout << (i + 1);
		for (int j = 0; j < ChessBoard::columnMax; j++)
		{
			std::cout << ChessBoard::getBoardSquare(i, j)->toString();
		}
		std::cout << std::endl;
	}
	return 0;
}