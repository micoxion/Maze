#include <iostream>
#include "Maze.h"

	maze.PrintMaze();

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