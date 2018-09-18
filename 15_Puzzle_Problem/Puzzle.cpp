#include "pch.h"
#include "Puzzle.h"
#include <iostream>
#include <iomanip>


//fill in the board 
Puzzle::Puzzle()
{
	//seed random number generator
	std::srand(time(0));

	//shuffle numbers array
	std::random_shuffle(&numbers[0], &numbers[14]);

	int numbersIndex = 0; //keep track of where we are in the numbers array
	
	int count = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == gapPos.getX() && j == gapPos.getY()) {
				board[i][j] = 0;
			} else {
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

//TODO: Change to use vector.swap() for swapping around tiles on board
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
			std::cout << "We are already at the top edge.\n";
			return;
		}
		//determine index of row above, same column
		targetPos.setNewPosition(currentPos.getX() - 1, currentPos.getY());
		//get value from one row above, same column
		tempValue = board[targetPos.getX()][targetPos.getY()];
		//swap value from gapPos with index from target position
		board[gapPos.getX()][gapPos.getY()] = tempValue;
		board[targetPos.getX()][targetPos.getY()] = 0;	//mark as gap
		//update gapPosition	
		gapPos = targetPos;

		std::cout << "\n\n";
		this->printPuzzle();
		break;

	case LEFT:
		//check if we are at left edge.
		if (currentPos.getY() == 0) {
			std::cout << "We are already at the left edge.\n";
			return;
		}
		//determine index of column to left, same row
		targetPos.setNewPosition(currentPos.getX(), currentPos.getY() - 1);
		//get value from one column to left, same row
		tempValue = board[targetPos.getX()][targetPos.getY()];
		//swap value from gapPos with index from target position
		board[gapPos.getX()][gapPos.getY()] = tempValue;
		board[targetPos.getX()][targetPos.getY()] = 0;	//mark as gap
		//update gapPosition
		gapPos = targetPos;

		std::cout << "\n\n";
		this->printPuzzle();
		break;

	case RIGHT:
		//check if we are at right edge.
		if (currentPos.getY() == columns - 1) {
			std::cout << "We are already at the rightmost edge.\n";
			return;
		}
		//determine index of column to right, same row
		targetPos.setNewPosition(currentPos.getX(), currentPos.getY() + 1);
		//get value from one column to the right, same row
		tempValue = board[targetPos.getX()][targetPos.getY()];
		//swap value from gapPos with index of target position
		board[gapPos.getX()][gapPos.getY()] = tempValue;
		board[targetPos.getX()][targetPos.getY()] = 0;	//mark as gap
		//update gapPosition.
		gapPos = targetPos;

		std::cout << "\n\n";
		this->printPuzzle();
		break;
	case DOWN:
		//check if we are at bottom edge.
		if (currentPos.getX() == rows - 1) {
			std::cout << "We are already at bottom edge.";
			return;
		}
		//determine index of row below, same column
		targetPos.setNewPosition(currentPos.getX() + 1, currentPos.getY());
		//get value from one row below, same column
		tempValue = board[targetPos.getX()][targetPos.getY()];
		//swap value from gapPos with index from target position
		board[gapPos.getX()][gapPos.getY()] = tempValue;
		board[targetPos.getX()][targetPos.getY()] = 0;	//mark as gap
		//update gapPosition
		gapPos = targetPos;

		std::cout << "\n\n";
		this->printPuzzle();

		break;

	}
}


Puzzle::~Puzzle()
{
}
