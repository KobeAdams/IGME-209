#pragma once
struct Vertex
{
	int xPos;
	int yPos;
	int hueristic;
	int lowestCost;
	bool visited;
	int weight;
	Vertex* previous;
};
