#pragma once
#include <Windows.h>

class Maze {
public:
	void Draw();
	Maze();
	~Maze();
	void StartGame();
	void DisplayMaze();
private:
	void FillGridWithWalls();
	void Dig();
	void DigDirection(int);
	bool ValidDirection(int);
	bool AnyValidDirection();
	void GenerateStartPos();
	void SpawnPlayer();
	void SpawnEnd();
	

	COORD startPos;
	COORD playerPos;
	COORD digPos;
	COORD dndPos;

	bool finished;

	std::stack<COORD> digStack;

	static const int WIDTH = 51, HEIGHT = 51;
	static const char WALL = (char)219;
	char grid[WIDTH][HEIGHT];
	
};