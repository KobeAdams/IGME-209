#pragma once
#include "Vertex.h"
#include <vector>
using namespace std;
class Graph
{
public:
	Graph();
	~Graph();

	void AddNode(Vertex* node);
	void AddEdge(int vert1, int vert2, int weight = 1);

	int GetNodeIndex(int x, int y);
	int GetNodeIndex(Vertex* v);
	Vertex* GetNode(int x, int y);
	Vertex* GetNode(Vertex* v);

	void PrintNodes();
	void PrintMatrix();

	bool IsAdjacent(int x, int y);
	void Reset();
	void SetStart(int x, int y);
	void SetEnd(int x, int y);
	void AStarSearch();
	Vertex* endVertex;

private:
	vector<Vertex*> nodes;
	int** matrix;
	Vertex* StartVertex;
	Vertex* currentVertex;

	vector<Vertex*> closedList;
	vector<Vertex*> openList;

	Vertex* GetUnvisitedNeighbor(int v);
	Vertex* GetUnvisitedNeighbor(Vertex* v);
	Vertex* GetLowestPriority();
	void RemoveVertex(Vertex* v, bool open = true);

};