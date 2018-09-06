#include "Position2D.h"
#include <algorithm>
#include <iostream>
#pragma once

enum Direction { UP, DOWN, LEFT, RIGHT};

class Puzzle
{
private:
	static const int rows = 4;	//how many rows on board
	static const int columns = 4;	//how many columns on board
	int numbers[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	
	Position2D gapPos = Position2D(1, 0);	//gap position on board
	char gapSymbol = 219;	//ASCII value to use for gap symbol
	int board[rows][columns];	//an array representing the board
public:
	Puzzle();	//default constructor
	void printPuzzle();	//prints state of puzzle
	void moveBlank(Direction direction);
	~Puzzle();	//deconstructor
};

