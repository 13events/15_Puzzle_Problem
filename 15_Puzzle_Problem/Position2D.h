#include "pch.h"

//Structure used to hold x,y coordinates for gap position
struct Position2D {
	int x;
	int y;

	//basic constructor
	Position2D(int x, int y) {
		this->x = x;
		this->y = y;
	}

	//returns x value
	int getX(){
		return this->x;
	}
	
	//returns y value
	int getY(){
		return this->y;
	}
};