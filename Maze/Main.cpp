//get key code here etc.
#include <iostream>
#include <stack>
#include <string>
#include "Maze.h"
#include "Windows.h"

using std::cout;
using std::endl;
using std::cin;

class ExampleClass {
public:
	void Fun();
};

void Fun() {
	cout << "FUN!";
}

void main() {
	Maze maze;
	maze.DisplayMaze();

	int key = getKey();
	while (key != VK_ESCAPE) {
		if (3 == 4) {
			cout << "nice";
		}
	}

}

int getKey() {
	int result = 0;
	while (result == 0) {
		short MAX_SHORT = 0x7FFF; //111111111111111
		if (GetAsyncKeyState(VK_LEFT) & MAX_SHORT) {
			result = VK_LEFT;
		}
		else if (GetAsyncKeyState(VK_UP) & MAX_SHORT) {
			result = VK_UP;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & MAX_SHORT) {
			result = VK_RIGHT;
		}
		else if (GetAsyncKeyState(VK_DOWN) & MAX_SHORT) {
			result = VK_DOWN;
		}
	}
	return result;
}