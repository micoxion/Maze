#pragma once

class Maze {
public:
	void Draw();
	Maze();
	~Maze();
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

	static const int WIDTH = 10, HEIGHT = 10;
	static const char WALL = (char)219;
	char grid[WIDTH][HEIGHT];
	
};