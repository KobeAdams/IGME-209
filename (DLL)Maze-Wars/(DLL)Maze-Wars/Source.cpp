#include "pch.h"
#include "Vertex.h"
#include "Graph.h"
#include <vector>

#include <iostream>

using namespace std;


struct Point
{
	int x;
	int y;
};

int** maze;
int mazeHeight, mazeWidth;
int* xpositions = new int[1, 2, 3, 4, 5];
int* ypositions = new int[1, 2, 3, 4, 5];
int* currentX = 0, *currentY = 0;
int startX, startY;
int endX, endY;

Graph graph;
vector<Point> steps;
bool initial;
int currentPos = 0;
__declspec(dllexport)char* GetTeam()
{
	return (char*)"Cameron Adams";
}

__declspec(dllexport) bool SetMaze(const int** data, int width, int height)
{
	if (maze != nullptr)
	{
		DeleteMaze();
	}
	mazeHeight = height;
	mazeWidth = width;
	if (height <= 0 || width <= 0)
	{
		return false;
	}
	maze = new int* [width];
	for (size_t i = 0; i < width; i++)
	{
		maze[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			maze[i][j] = data[i][j];
		}
	}
	

	

	if (maze != nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

__declspec(dllexport) int** GetMaze(int& width, int& height)
{
	if (mazeHeight == height && mazeWidth == width)
		return maze;
	else if (maze != nullptr)
		return maze;
	else
		return nullptr;
}

__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos)
{
	bool available = false;
	if (initial == false)
	{
		for (size_t i = 0; i < mazeWidth; i++)
		{
			for (size_t j = 0; j < mazeHeight; j++)
			{
				if (maze[i][j] != 1)
				{
					Vertex* node = new Vertex;
					node->xPos = i;
					node->yPos = j;
					node->hueristic = abs(mazeWidth - (int)i) + abs(mazeHeight - (int)j);
					node->weight = 0;
					node->lowestCost = INT_MAX;
					graph.AddNode(node);

				}
			}
		}

		for (size_t i = 0; i < mazeWidth; i++)
		{
			for (size_t j = 0; j < mazeHeight; j++)
			{
				int pt1 = graph.GetNodeIndex(i, j);

				if (i - 1 >= 0 && maze[i - 1][j] != 1)
				{
					int pt2 = graph.GetNodeIndex(i - 1, j);
					graph.AddEdge(pt1, pt2);
					
				}
				if (i + 1 < mazeWidth && maze[i + 1][j] != 1)
				{
					int pt2 = graph.GetNodeIndex(i + 1, j);
					graph.AddEdge(pt1, pt2);
					
				}
				if (j - 1 >= 0 && maze[i][j - 1] != 1)
				{
					int pt2 = graph.GetNodeIndex(i, j - 1);
					graph.AddEdge(pt1, pt2);
					
				}
				if (j + 1 >= 0 && maze[i][j + 1] != 1)
				{
					int pt2 = graph.GetNodeIndex(i, j + 1);
					graph.AddEdge(pt1, pt2);
					
				}
			}
			
		}

		initial = true;

		graph.SetStart(startX, startY);
		graph.SetEnd(endX, endY);

		graph.AStarSearch();

		Vertex* end = graph.endVertex;
		while (end != nullptr)
		{
			Point s;
			s.y = end->yPos;
			s.x = end->xPos;
			steps.insert(steps.begin(), s);
			end = end->previous;
		}
			
	
		
	}
	currentX = &steps[currentPos].x;
	currentY = &steps[currentPos].y;
	currentPos++;
	if (currentPos >= steps.size())
		Restart();
	return available;
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

__declspec(dllexport) bool SetEnd(int xpos, int ypos)
{
	endX = xpos;
	endY = ypos;
	if (endX != NULL && endY != NULL)
	{
		return true;
	}
	else
		return false;
}

__declspec(dllexport) bool GetEnd(int xpos, int ypos)
{
	xpos = endX;
	ypos = endY;
	if (xpos != NULL && ypos != NULL)
	{
		return true;
	}
	else
		return false;
}

__declspec(dllexport) bool Restart()
{
	currentX = 0;
	currentY = 0;
	currentPos = 0;
	if (currentPos == 0)
	{
		return true;
	}
	else
		return false;
}

void DeleteMaze()
{

}




