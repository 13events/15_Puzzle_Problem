// 15_Puzzle_Problem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Puzzle.h"

int main()
{
	Puzzle myBoard = Puzzle();
	myBoard.printPuzzle();
	myBoard.moveBlank(UP);
	myBoard.moveBlank(UP);
	std::getchar();
}


