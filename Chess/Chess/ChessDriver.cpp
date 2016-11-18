#include "ChessBoard.h"
#include <iostream>
#include "FileIO.h"

void displayBoard() 
{
	std::cout << "  A   B   C   D   E   F   G   H " << std::endl;
	for (int i = 0; i < ChessBoard::rowMax; i++)
	{
		std::cout << (i + 1);
		for (int j = 0; j < ChessBoard::columnMax; j++)
		{
			std::cout << ChessBoard::getBoardSquare(i, j)->toString();
		}
		std::cout << std::endl;
	}
}

int main(int argc, char** argv) 
{
	bool whitesTurn = true;
	ChessBoard::initBoard();
	//displayBoard();
	FileIO fileReader;
	if (!GameLogger::Initialize("..\\Logs\\","Chess.log")) return -1;
	if (!fileReader.Parser("..\\Data\\Placement.txt")) return -1;
	fileReader.ParseGame();
	//if (!fileReader.Parser("..\\Data\\MoveTests.txt")) return -1;
	//fileReader.ParseGame();
	displayBoard();
	while (!ChessBoard::checkmate())
	{
		std::string move;
		std::getline(std::cin, move);
		if (whitesTurn) {
			if (ChessBoard::getBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a'))->getPiece()->getPieceColor() == 'l') {
				fileReader.ParseGame(move);
				whitesTurn = false;
				displayBoard();
			}
			else
			{
				std::cout << "That piece is not yours." << std::endl;
			}
		}
		else 
		{
			if (ChessBoard::getBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a'))->getPiece()->getPieceColor() == 'd') {
				fileReader.ParseGame(move);
				whitesTurn = true;
				displayBoard();
			}
			else
			{
				std::cout << "That piece is not yours." << std::endl;
			}
		}
	}

	return 0;
}