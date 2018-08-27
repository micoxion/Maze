#include <iostream>
#include <stack>
#include <time.h>
#include <stdexcept>
#include <Windows.h>
#include "Maze.h"

using std::cout;
using std::cin;
using std::endl;

//Calls necessary Maze methods to initialize and Generate maze
void Maze::Draw() {
	GetColors();
	FillGridWithWalls();
	GenerateStartPos();
	Dig();
	DisplayMaze();
	SpawnEnd();
}

//Draws the player and begins the game loop
void Maze::Start() {
	DrawPlayer(startPos);
	int keyPressed;

	while (!playerWin) {
		keyPressed = GetKey();
		//Up
		if (keyPressed == 38) {
			
		}//Right 
		else if (keyPressed == 39) {
			
		}//Down 
		else if (keyPressed == 40) {

		}//Left
		else if (keyPressed == 37) {

		}
	}
}

void Maze::SpawnEnd() {

}

//Places player according to COORD parameter
void Maze::DrawPlayer(COORD playerPos) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPos);
	cout << PLAYER;
}

void Maze::DisplayMaze() {
	SetTextColor(wallColor);
	for (int row = 0; row < HEIGHT; row++) {
		for (int column = 0; column < WIDTH; column++) {
			cout << grid[row][column];
		}
		cout << row << endl;
	}
}

void Maze::Dig() {
	digPos = startPos;
	bool mazeComplete = false;
	int direction;

	while (!mazeComplete) {
		//Loop as long as any direction can be dug in
		while (AnyValidDirection()) {
			direction = rand() % 4 + 1;
			if (ValidDirection(direction)) {
				digStack.push(digPos);
				DigDirection(direction);
			}
		}

		if (!digStack.empty()) {
			digStack.pop();
			if (!digStack.empty())
				digPos = digStack.top();
		}
		else {
			mazeComplete = true;
		}
	}
}

void Maze::DigDirection(int direction) {
	//Up
	if (direction == 1) {
		grid[digPos.Y - 1][digPos.X] = ' ';
		grid[digPos.Y - 2][digPos.X] = ' ';
		digPos = { digPos.X, digPos.Y - 2 };
	}//Right
	else if (direction == 2) {
		grid[digPos.Y][digPos.X + 1] = ' ';
		grid[digPos.Y][digPos.X + 2] = ' ';
		digPos = { digPos.X + 2, digPos.Y };
	}//Down
	else if (direction == 3) {
		grid[digPos.Y + 1][digPos.X] = ' ';
		grid[digPos.Y + 2][digPos.X] = ' ';
		digPos = { digPos.X, digPos.Y + 2 };
	}//Left
	else if (direction == 4) {
		grid[digPos.Y][digPos.X - 1] = ' ';
		grid[digPos.Y][digPos.X - 2] = ' ';
		digPos = { digPos.X - 2, digPos.Y };
	}
}

bool Maze::AnyValidDirection() {
	return ValidDirection(1) || ValidDirection(2) || 
		ValidDirection(3) || ValidDirection(4);
}

bool Maze::ValidDirection(int direction) {
	//Up
	if (digPos.Y > 2 && direction == 1) { 
		return grid[digPos.Y - 2][digPos.X] == WALL;
	}//Down
	else if (digPos.Y < HEIGHT - 3 && direction == 3) {
		return grid[digPos.Y + 2][digPos.X] == WALL;
	}//Right 
	else if (digPos.X < WIDTH - 3 && direction == 2) {
		return grid[digPos.Y][digPos.X + 2] == WALL;
	}//Left
	else if (digPos.X > 2 && direction == 4) {
		return grid[digPos.Y][digPos.X - 2] == WALL;
	}
	else {
		return false;
	}
}

void Maze::FillGridWithWalls() {
	for (int row = 0; row < HEIGHT; row++) {
		for (int column = 0; column < WIDTH; column++) {
			grid[row][column] = WALL;
		}
	}
}

//Randomly generate and place maze start position
void Maze::GenerateStartPos() {
	srand(time(NULL));
	bool notOdd = false;
	short int xCoord = 3;
	short int yCoord = 3;
	while (!notOdd) {
		xCoord = rand() % WIDTH;
		yCoord = rand() % HEIGHT;
		if (xCoord % 2 != 0 && yCoord % 2 != 0) {
			notOdd = true;
		}
	}
	
	grid[yCoord][xCoord] = 'S';
	startPos = { xCoord, yCoord };
}

Maze::Maze() {

}

Maze::~Maze() {

}

int Maze::GetKey() {
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

void Maze::SetTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

//Get text colors from user
void Maze::GetColors() {
	srand(NULL);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool randomizeAll = false;

	//looping through select console text attribute values
	//displaying colors for choice to user
	for (int k = 10; k < 15; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " Color Example" << endl;
	}

	int response;
	cout << "Please choose a color for the maze (press 0 to randomize, press 1 to randomize all): ";
	cin >> response;

	if (response == 0)
		wallColor = rand() % 6 + 10;
	else if (response == 1)
		randomizeAll = true;
	else
		wallColor = response;

	if (randomizeAll) {
		wallColor = rand() % 6 + 10;
		playerColor = rand() % 6 + 10;
		startEndColor = rand() % 6 + 10;
	}
	else {
		cout << "Please choose a color for your player (press 0 to randomize): ";
		cin >> response;
		if (response == 0)
			playerColor = rand() % 6 + 10;
		else
			playerColor = response;
		cout << endl;

		cout << "Please choose a color for the start and end signs (press 0 to randomize): ";
		cin >> response;
		if (response == 0)
			playerColor = rand() % 6 + 10;
		else
			playerColor = response;
		cout << endl;
	}
}