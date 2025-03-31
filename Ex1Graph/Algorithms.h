#pragma once
#include "Graph.h"
namespace graph
{
	class Algorithms
	{
	private:

	public:
		static Graph* BFS(Graph* g, int root);

		static Graph* DFS(Graph* g, int root);

		static Graph* dijkstra(Graph* g, int root);

		static Graph* prim(Graph* g);

		static Graph* kruskal(Graph* g);

	};
}


