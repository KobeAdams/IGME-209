#include "Graph.h";
#include "Vertex.h"
Graph::Graph()
{

}



Graph::~Graph()
{
	if (matrix != nullptr)
	{
		for (size_t i = 0; i < nodes.size(); i++)
		{
			delete [] matrix[i];
		}
		delete[] matrix;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
	nodes.clear();
}

void Graph::SetStart(int x, int y)
{
	StartVertex = new Vertex();
}

bool Graph::IsAdjacent(int x, int y)
{

}

void Graph::AddNode(Vertex* v)
{
	nodes.insert(nodes.begin(), v);
}

bool Graph::IsAdjacent(int v1, int v2)
{
	return matrix[v1][v2] != 0;
}


