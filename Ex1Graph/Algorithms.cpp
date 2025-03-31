#include "Algorithms.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include "minHeap.h"

namespace graph
{
	Graph* Algorithms::BFS(Graph* graph, int root)
	{
		Graph* ans = new Graph(graph->getSize(),true);
		Queue<int> q = Queue<int>();
		bool* visited = new bool[graph->getSize()]();
		visited[root] = true;
		q.add(root);
		while (!q.isEmpty())
		{
			int parent = q.pop();
			
			for (int i = 0; i < graph->getSize(); i++)
			{
				
				if (graph->getEdge(parent,i) != NULL)
				{
					if (!visited[i])
					{

						visited[i] = true;
						ans->addEdge(parent, i, 0);
						q.add(i);
					}
				}
			}
		}
		delete[] visited;
		return ans;
	}

	Graph* Algorithms::DFS(Graph* g, int root)
	{
		Graph* ans = new Graph(g->getSize(),true);
		Stack<int> s;
		s.push(root);
		bool* visited = new bool[g->getSize()]();
		while (!s.isEmpty())
		{
			int parent = s.pop();
			if (!visited[parent])
			{
				visited[parent] = true;
				for (int i = 0; i < g->getSize(); i++)
				{
					if (g->getEdge(parent, i) != NULL)
					{
						if (!visited[i])
						{
							ans->addEdge(parent, i, 0);
							s.push(i);
						}
					}
				}
			}
		}
		delete[] visited;
		return ans;
	}

	Graph* Algorithms::dijkstra(Graph* g, int root)
	{
		int n = g->getSize();
		int* dist = new int[n];
		int* parent = new int[n];
		bool* visited = new bool[n]();
		Graph* ans = new Graph(n,true);
		MinHeap<Edge*> edges;
		dist[root] = 0;
		parent[root] = root;
		edges.add(new Edge(root,-1,0));
		for (int i = 0; i < n; i++)
		{
			if (i != root)
			{
				parent[i] = -1;
				dist[i] = INT_MAX;
			}
		}
		while (!edges.isEmpty())
		{
			Edge* shortest = edges.removeMin();
			int v = shortest->getParent();
			if (!visited[v])
			{
				visited[v] = true;
				for (int i = 0; i < n; i++)
				{
					if (g->getEdge(v, i) != NULL)
					{
						int newDist = dist[v] + g->getEdge(v, i)->getWeight();
						if (newDist < dist[i])
						{
							parent[i] = v;
							dist[i] = newDist;
							edges.update(new Edge(i,-1, newDist));
						}
					}
				}
			}
			delete shortest;
			
		}

		for (int i = 0; i < n; i++)
		{
			int p = parent[i];
			if (parent[i] != -1&&g->getEdge(p,i)!=NULL)
			{
				ans->addEdge(p, i, g->getEdge(p, i)->getWeight());
			}
			
		}
		delete[] dist;
		delete[] parent;
		delete[] visited;
		return ans;
	}
	Graph* Algorithms::prim(Graph* g)
	{
		int n = g->getSize();
		Graph* ans = new Graph(n,true);
		bool* visited = new bool[n]();
		int* minWeight = new int[n];
		int* parent = new int[n];
		for (int i = 0; i < n; i++)
		{
			minWeight[i] = INT_MAX;
			parent[i] = -1;
		}
		int root = -1;
		for (int i = 0; i < n && root == -1; i++) {
			for (int j = 0; j < n; j++) {
				if (g->getEdge(i, j) != NULL) {
					root = i;
					break;
				}
			}
		}
		if (root == -1)
		{
			return NULL;
		}
		minWeight[root] = 0;
		MinHeap<Edge*> heap;
		heap.add(new Edge(root, -1, 0));
		while (!heap.isEmpty())
		{
			Edge* e = heap.removeMin();
			int v = e->getParent();
			if (!visited[v])
			{
				visited[v] = true;
				if (parent[v] != -1)
				{
					ans->addEdge(parent[v], v, e->getWeight());
				}
				for (int i = 0; i < n; i++)
				{
					Edge* u = g->getEdge(v, i);
					if (u != NULL)
					{
						int w = u->getWeight();
						if (!visited[i]&&w<minWeight[i])
						{
							minWeight[i] = w;
							parent[i] = v;
							heap.add(new Edge(i, -1, w));
						}
					}
				}
			}
			delete e;
		}
		delete[] visited;
		delete[] minWeight;
		delete[] parent;
		return ans;
	}

	Graph* Algorithms::kruskal(Graph* g)
	{
		int n = g->getSize();
		Graph* ans = new Graph(n, true);
		return NULL;
	}




}