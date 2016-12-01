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
	bool checkmate = false;
	ChessBoard::initBoard();
	//displayBoard();
	FileIO fileReader;
	if (!GameLogger::Initialize("..\\Logs\\","Chess.log")) return -1;
	if (!fileReader.Parser("..\\Data\\Placement.txt")) return -1;
	fileReader.ParseGame(whitesTurn,checkmate);
	//if (!fileReader.Parser("..\\Data\\Check.txt")) return -1;
	//fileReader.ParseGame(!whitesTurn);
	displayBoard();
	while (!checkmate)
	{
		std::string move;
		std::getline(std::cin, move);
		if (whitesTurn) {
			std::cout << "Whites turn" << std::endl;
			if (ChessBoard::getBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a'))->getPiece()->getPieceColor() == 'l') {
				if (fileReader.ParseGame(move, whitesTurn, checkmate))
				{
					whitesTurn = false;
					if (!checkmate) {
						if (ChessBoard::check(whitesTurn))
						{
							std::cout << "Black King is in check\n";
						}
						else
						{
							std::cout << "Black King is not in check\n";
						}
					}
					else 
					{
						std::cout << "Checkmate on Dark King\n";
					}
				}
				displayBoard();


			}
			else
			{
				std::cout << "That piece is not yours." << std::endl;
			}
		}
		else 
		{
			std::cout << "Blacks turn" << std::endl;
			if (ChessBoard::getBoardSquare((move.at(1) - '0' - 1), (move.at(0) - 'a'))->getPiece()->getPieceColor() == 'd') {
				if (fileReader.ParseGame(move,whitesTurn,checkmate)) 
				{
					whitesTurn = true;
					if (!checkmate) 
					{
						if (ChessBoard::check(whitesTurn))
						{
							std::cout << "Light King is in check\n";
						}
						else
						{
							std::cout << "Light King is not in check\n";
						}
					}
					else 
					{
						std::cout << "Checkmate on Light King\n";
					}
				}
				displayBoard();
			}
			else
			{
				std::cout << "That piece is not yours." << std::endl;
			}
		}
	}
	std::cout << "End of game\n";
	return 0;
}