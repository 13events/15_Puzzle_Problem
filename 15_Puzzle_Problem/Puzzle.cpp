#include "pch.h"
#include "Puzzle.h"
#include <iostream>
#include <iomanip>


//fill in the board 
Puzzle::Puzzle()
{
	//seed random number generator
std:srand(time(0));

	//shuffle numbers array
	std::random_shuffle(&numbers[0], &numbers[14]);

	int numbersIndex = 0;
	
	
	int count = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
				if (i == gapPos.getX() && j == gapPos.getY()) {
					board[i][j] = 0;
				}
				else {
					board[i][j] = numbers[numbersIndex];
					numbersIndex++;
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
	Position2D currentPos = gapPos;
	Position2D targetPos;
	int tempValue;

	//version - 1
	switch (direction) {
	case UP:
		//check if we are at top edge.
		if (currentPos.getX() == 0) {
			std::cout << "We are already at the top edge.";
			return;
		}
		
		//determine index of row above, same column
		targetPos.setNewPosition(currentPos.getX() - 1, currentPos.getY());
		//get value from one row above, same column
		tempValue = board[targetPos.getX()][targetPos.getY()];
		//swap value from gapPos with index from target position
		board[gapPos.getX()][gapPos.getY()] = tempValue;
		board[targetPos.getX()][targetPos.getY()] = 0;
		//update gapPosition	
		gapPos = targetPos;

		std::cout << "\n\n";
		this->printPuzzle();
		
		break;
	case LEFT:
		//check if we are at left edge.
		//determine index of column to left, same row
		//get value from one column to left, same row
		//swap value from gapPos with index from target position
		//update gapPosition
		break;
	case RIGHT:
		//check if we are at right edge.
		//determine index of column to right, same row
		//get value from one column to the right, same row
		//swap value from gapPos with index of target position
		//update gapPosition.
		break;
	case DOWN:
		//check if we are at bottom edge.
		//determine index of row below, same column
		//get value from one row below, same column
		//swap value from gapPos with index from target position
		//update gapPosition
		break;

	}
}


Puzzle::~Puzzle()
{
}
