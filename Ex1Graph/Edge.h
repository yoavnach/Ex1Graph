#pragma once
namespace graph
{
	class Edge
	{
	private:
		int weight;
		int origin;
		int dest;
	public:
		Edge(int origin,int dest,int weight);

		int getWeight();


		int getParent()
		{
			return this->origin;
		}

		bool operator==(Edge const& b)
		{
			return this->origin == b.origin && this->dest == b.dest;
		}
		bool operator<(Edge const& b)
		{
			return this->weight < b.weight;
		}
		bool operator>(Edge const& b)
		{
			return this->weight > b.weight;
		}
		bool operator>=(Edge const& b)
		{
			return this->weight >= b.weight;
		}
		bool operator<=(Edge const& b)
		{
			return this->weight <= b.weight;
		}

		

	};
}


