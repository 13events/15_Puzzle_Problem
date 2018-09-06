#include "pch.h"
#include "Puzzle.h"
#include <iostream>
#include <iomanip>


//fill in the board 
Puzzle::Puzzle()
{

	int count = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
				if (i == gapPos->getX() && j == gapPos->getY()) {
					board[i][j] = 0;
				}
				else {
					board[i][j] = count;
					count++;
				}
		}
	}
}

//prints a nicely formatted representation of the board
void Puzzle::printPuzzle()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			//if we are at gap location, put a gap symbol
			if (board[i][j] == 0) {
				std::cout << std::right << std::setw(7) << gapSymbol;
			}
			else {
				std::cout << std::right << std::setw(7) << board[i][j];
			}
			

		}
		std::cout << "\n";
	}
}

//move the blank space in a direction while also switching the position of the values and the blank
void Puzzle::moveBlank(Direction direction)
{

	switch (direction) {
	case UP:
		//check if we are at edge



	}
}


Puzzle::~Puzzle()
{
}
