// 15_Puzzle_Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Puzzle.h"
#include "Node.h"

int main()
{
	Puzzle myBoard = Puzzle();
	char userInput = ' ';

	Node myNode = Node(4, 4);
	fillMatrix(myNode.matrix, myNode.rows, myNode.cols);
	printMatrix(myNode.matrix, myNode.rows, myNode.cols);
	newNode(myNode.matrix, myNode.rows, myNode.cols, 0, 0, 1, 1, 2, myNode.parent);

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


