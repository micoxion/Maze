#include <iostream>
#include <Windows.h>
#include <stack>
#include <numeric>
using namespace std;

int getKey();
const char WALL = (char)219;
const char SPACE = ' ';
const int SIZE_X = 10;
const int SIZE_Y = 10;

class Maze {
private:
	char map[SIZE_X][SIZE_Y];
public:
	void PrintMaze() {

		for (int i = 0; i < SIZE_X; i++) {
			for (int j = 0; j < SIZE_Y; j++) {
				COORD mapCoord = { i,j };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mapCoord);
				cout << WALL;
			}
		}
	}

	void GenerateStartingPoint() {
		srand(NULL);

	}
};

void main() {
	Maze maze;

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