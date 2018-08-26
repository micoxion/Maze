//get key code here etc.
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "Maze.h"
#include "Windows.h"

using std::cout;
using std::endl;
using std::cin;

int getKey();

void main() {
	Maze maze;
	maze.Draw();
	maze.Start();
}