//yoav1.nach@gmail.com

#pragma once
#include "Edge.h"

namespace graph
{
	class Graph
	{
	private:
		Edge*** edges;
		int size;
		bool directed;
	public:
		Graph(int size,bool directed);

		void addEdge(int origin, int dest, int weight);

		void removeEdge(int origin, int dest);

		void printGraph();

		int getSize();

		Edge* getEdge(int i, int j)
		{
			return this->edges[i][j];
		}

		int getEdgesSize();

		Edge** getEdges();

		~Graph();

	};
}


