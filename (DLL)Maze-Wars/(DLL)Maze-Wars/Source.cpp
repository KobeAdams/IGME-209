#include "pch.h"
#include <iostream>

using namespace std;

int** maze;
int mazeHeight, mazeWidth;
int* xpositions = new int[0, 1, 2, 3, 4];
int* ypositions = new int[0, 1, 2, 3, 4];
int* currentX = 0, *currentY = 0;
int startX, startY;
int endX, endY;
__declspec(dllexport)char* GetTeam()
{
	return (char*)"Cameron Adams";
}

__declspec(dllexport)void SetMaze(const int** data, int width, int height)
{
	mazeHeight = height;
	mazeWidth = width;
	maze = new int* [width];
	for (size_t i = 0; i < width; i++)
	{
		maze[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			maze[i][j] = data[i][j];
		}
	}
}

__declspec(dllexport) int** GetMaze(int& width, int& height)
{
	if (mazeHeight == height && mazeWidth == width)
		return maze;
	else
		return 0;
}

__declspec(dllexport) void GetNextPosition(int& xpos, int& ypos)
{
	if (ypositions + 5 - currentY != 0)
		currentY++;
	else
		currentX++;
	
}
__declspec(dllexport) void SetStart(int xpos, int ypos)
{
	startX = xpos;
	startY = xpos;
}

__declspec(dllexport) void GetStart(int& xpos, int& ypos)
{
	if (startX != NULL)
	{
		currentX += startX;
	}
	else
	{
		startX = -1;
	}
	if (startY != NULL)
	{
		currentY += startY;
	}
	else
	{
		startY = -1;
	}
	std::cout << currentX << ", " << currentY;
}

__declspec(dllexport) void SetEnd(int xpos, int ypos)
{
	endX = xpos;
	endY = ypos;
}

__declspec(dllexport) void GetEnd(int xpos, int ypos)
{

}





