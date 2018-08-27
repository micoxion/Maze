#pragma once
#include <Windows.h>

class Maze {
public:
	void Draw();
	Maze();
	~Maze();
	void Start();
	
private:
	//Drawing functions:
	void FillGridWithWalls();
	void DrawPlayer(COORD);
	void DisplayMaze();
	void GenerateStartPos();
	void SetTextColor(int);

	//Logic functions:
	bool ValidDirection(int);
	bool AnyValidDirection();

	//Grid editing functions:
	void Dig();
	void DigDirection(int);
	void SpawnEnd();
	
	//User input functions
	int GetKey();
	void GetColors();

	//Position storing variables
	COORD startPos;
	COORD playerPos;
	COORD digPos;
	COORD dndPos;

	bool playerWin;

	//text attribute values for giving text color
	int wallColor;
	int playerColor;
	int startEndColor;

	std::stack<COORD> digStack;

	//static class variables
	static const int WIDTH = 51, HEIGHT = 51;
	static const char WALL = (char)219;
	static const char PLAYER = 'P';
	
	char grid[WIDTH][HEIGHT];
};