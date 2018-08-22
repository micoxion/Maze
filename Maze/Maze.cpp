#include <iostream>
#include "Maze.h"

using namespace std;



Maze::Maze() {

}

Maze::~Maze() {

}

//Fill the maze with walls <- don't do that
void Maze::FillMazeWithWalls() {
	for (int row = 0; row < HEIGHT; row++) {
		for (int column = 0; column < WIDTH; column++) {
			grid[row][column] = WALL;
		}
	}
}