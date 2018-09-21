#pragma once
#include <vector>
#include <iostream>
#include <string.h>


int row[] = { 1,0,-1,0 };
int col[] = { 0,-1,0,1 };

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

	Node();

	//Constructor
	Node(int row, int col) : matrix(row, std::vector<int>(col)) {


		this->rows = row;
		this->cols = col;
		//fillMatrix(this->matrix, this->rows, this->cols);


	}
};

// HELPER FUNCTIONS //

//fill the matrix with zeros
void fillMatrix(std::vector<std::vector<int>> &matrix, int rows, int cols) {
	std::vector<std::vector<int>>::iterator row;
	std::vector<int>::iterator col;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
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

//print out a matrix
void printMatrix(std::vector < std::vector<int>> matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

//allocate a new node
Node* newNode(std::vector<std::vector<int>> matrix, 
	int rows, int cols, int x, int y, int newX, int newY, int level, Node* parent) {
	Node* node = new Node(rows, cols);

	//set pointer for path to root
	node->parent = parent;

	std::copy(matrix.begin(), matrix.end(), node->matrix.begin());
		
	//debug code
	std::cout << "Copied Matrix: \n";
	printMatrix(node->matrix, rows, cols);

	std::cout << "Original Matrix: \n";
	printMatrix(matrix, rows, cols);

	//move tile 1 position
	std::swap(node->matrix[x][y], node->matrix[newX][newY]);

	//set number of  misplaced tiles
	node->cost = INT_MAX;

	//set number of moves so far
	node->level = level;

	//update new blank tile coordinates
	node->x = newX;
	node->y = newY;

	return node;
}
	

//calculate the number of misplaced tiles
// the number of non-blank tiles that are not in their goal position
int calculateCost(std::vector<std::vector<int>> initial, std::vector<std::vector<int>> final) {
	int count = 0;
	for (int i = 0; i < initial.size(); i++) {
		for (int j = 0; j < initial.size(); j++) {
			if (initial[i][j] && initial[i][j] != final[i][j]) {
				count++;
			}
		}
	}
	return count;
}
