
#include "Graph.h"
#include "Algorithms.h"
#include "Queue.h"
#include "MinHeap.h"


using namespace graph;

int main()
{


	Graph* graph = new Graph(10,true);
	graph->addEdge(0, 1, 10);
	graph->addEdge(0, 2, 5);
	graph->addEdge(0, 4, 8);
	graph->addEdge(1, 7, 12);
	graph->addEdge(2, 6, 67);
	graph->addEdge(2, 5, 15);
	graph->addEdge(5, 3, 78);
	graph->addEdge(4, 9, 3);
	graph->addEdge(7, 8, 1233);
	graph->addEdge(8, 9, 76);
	graph->addEdge(5, 9, 8);

	graph->printGraph();
	std::cout << "\n";

	Graph* g = Algorithms::BFS(graph,0);

	g->printGraph();
	std::cout << "\n";
	delete g;

	g = Algorithms::DFS(graph, 0);

	g->printGraph();

	delete g;

	g = Algorithms::dijkstra(graph, 0);

	g->printGraph();

	delete g;

	//g = Algorithms::kruskal(graph);

	//g->printGraph();

	//delete g;

	g = Algorithms::prim(graph);

	g->printGraph();

	delete g;


	

	

	delete graph;

	
}