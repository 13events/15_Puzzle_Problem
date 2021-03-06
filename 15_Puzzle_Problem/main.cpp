// 15_Puzzle_Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Puzzle.h"

int main()
{
	Puzzle myBoard = Puzzle();
	char userInput = ' ';

	std::cout << "Welcome to the 15-Puzzle Program.\n" <<
		"Use the (A, S, D, W) keys to move \nLeft, Down, Right " <<
		"and Up, respectively." << 
		"\nPress 'Q' to quit.\n\n";

	myBoard.printPuzzle();


	while (userInput != 'q') {
		std::cout << "Next Move: ";
		std::cin >> userInput;
		switch (userInput) {
		case 'a': 
			myBoard.moveBlank(LEFT);
			break;
		case 's':
			myBoard.moveBlank(DOWN);
			break;
		case 'd':
			myBoard.moveBlank(RIGHT);
			break;
		case 'w':
			myBoard.moveBlank(UP);
			break;
		default:
			break;
		}
		
	}

}


