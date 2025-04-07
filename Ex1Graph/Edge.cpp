//yoav1.nach@gmail.com

#include "Edge.h"
namespace graph
{
	Edge::Edge(int origin, int dest,int weight)
	{
		this->weight=weight;
		this->origin = origin;
		this->dest = dest;
	}

	int Edge::getWeight()
	{
		return this->weight;
	}

	
}
