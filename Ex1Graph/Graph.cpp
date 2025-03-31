#include "Graph.h"
#include <iostream>
namespace graph
{
	Graph::Graph(int size,bool directed)
	{
		this->size = size;
		this->directed = directed;
		this->edges = new Edge**[size];
		for (int i = 0; i < size; i++)
		{
			this->edges[i] = new Edge * [size];
			for (int j = 0; j < size; j++)
			{
				edges[i][j] = NULL;
			}
		}
	}

	void Graph::addEdge(int origin, int dest, int weight)
	{
		if (origin < 0 || origin >= this->size || dest < 0 || dest >= this->size)
		{
			throw "Out of the graph";
		}
		if (this->directed)
		{
			this->edges[origin][dest] = new Edge(origin, dest, weight);
		}
		else
		{
			this->edges[dest][origin] = new Edge(dest, origin, weight);
		}
		
	}

	void Graph::removeEdge(int origin, int dest)
	{
		if (origin < 0 || origin >= this->size || dest < 0 || dest >= this->size)
		{
			throw "Out of the graph";
		}
		if (this->directed)
		{
			delete this->edges[origin][dest];
			this->edges[origin][dest] = NULL;
		}
		else
		{
			delete this->edges[origin][dest];
			this->edges[origin][dest] = NULL;
			delete this->edges[dest][origin];
			this->edges[dest][origin] = NULL;
		}
		
	}

	void Graph::printGraph()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << "Vertice " << i<<": \n";
			for (int j = 0; j < this->size; j++)
			{
				if (this->edges[i][j] != NULL)
				{
					std::cout << "  weight: " << this->edges[i][j]->getWeight() << " to: " << j << "\n";
				}
					
			}

		}
	}

	int Graph::getSize()
	{
		return this->size;
	}

	int Graph::getEdgesSize()
	{
		int ans = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (this->edges[i][j] != NULL)
				{
					ans++;
				}
			}
		}
		return ans;
	}

	Edge** Graph::getEdges()
	{
		int edgesNum = this->getEdgesSize();
		Edge** ans = new Edge*[edgesNum];
		int count = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (this->edges[i][j] != NULL)
				{
					ans[count] = this->getEdge(i, j);
				}
			}
		}
		return ans;
	}

	Graph::~Graph()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (this->edges[i][j] != NULL)
				{
					delete this->edges[i][j];
					this->edges[i][j] = NULL;
				}
					
			}
			delete[] this->edges[i];
		}
		delete[] this->edges;

	}
}