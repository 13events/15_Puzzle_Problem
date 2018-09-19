#pragma once
#include <vector>

//Structure representing nodes in a tree
struct Node {

	//store parent node of current node
	//helps us trace back
	Node* parent;

	//declare matrix pointer
	std::vector<std::vector<int>> matrix;
	int rows, cols;

	//store gap coordinates
	int x, y;

	//store number of misplaced tiles
	int cost; 

	//store number of moves so far
	int level;

	Node(int row, int col): matrix(row, std::vector<int>(col)) {
 		

		this->rows = row;
		this->cols = col;
		this->fillMatrix();
		 
	}

	void fillMatrix() {
		std::vector<std::vector<int>>::iterator row;
		std::vector<int>::iterator col;

		for (int row = 0; row < this->rows; row++) {
			for (int col = 0; col < this->cols; col++) {
				matrix[row][col] = row + col + 1;
			}
		}
		/*for (row = matrix.begin(); row != matrix.end(); row++) {
			for (col = row->begin(); col != row->end(); col++)
			{
				*col = 0;
			}

		}*/

	}



};
