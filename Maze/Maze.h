#pragma once
#include <Windows.h>

class Maze {
public:
	void Draw();
	Maze();
	~Maze();
	void Start();
	
private:
	void FillGridWithWalls();
	void Dig();
	void DigDirection(int);
	bool ValidDirection(int);
	bool AnyValidDirection();
	void GenerateStartPos();
	void DisplayMaze();
	void DrawPlayer(COORD);
	void SpawnEnd();
	int GetKey();

	COORD startPos;
	COORD playerPos;
	COORD digPos;
	COORD dndPos;

	bool playerWin;

	int(*getKey)();

	std::stack<COORD> digStack;

	static const int WIDTH = 51, HEIGHT = 51;
	static const char WALL = (char)219;
	static const char PLAYER = 'P';
	char grid[WIDTH][HEIGHT];
	
};