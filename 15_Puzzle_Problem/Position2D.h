#include "pch.h"
#include <iostream>
#include "stdio.h"
#include <sstream>
//#include <string>

//Structure used to hold x,y coordinates for gap position
struct Position2D {
private:
	int x;
	int y;
public:
	//default constructor, set all to 0
	Position2D() {
		this->x = 0;
		this->y = 0;
	}
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

	void setNewPosition(int x, int y) {
		this->x = x;
		this->y = y;

	}
	std::string print() {
		
		std::ostringstream oss;
		oss << '(' << this->getX() << ',' << this->getY() << ')';
		return oss.str();
	}
};