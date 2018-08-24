#pragma once


class Maze {
public:
	Maze();
	~Maze();
	void StartGame();
private:
	void FillMazeWithWalls();
	static const int WIDTH = 10, HEIGHT = 10;
	static const char WALL = (char)219;
	char grid[WIDTH][HEIGHT];
	
};