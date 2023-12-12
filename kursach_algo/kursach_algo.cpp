#include <iostream>
#include <vector>
#include "Prim.h"
#include "Kruskal.h"
#include "OstovFinder.h"
#include "Edge.h"
#include <queue>

void print(const std::vector<Edge>& graph) {
	for (const auto& edge : graph) {
		std::cout << edge << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<Edge> graph{
		Edge(1, 2, 3),
		Edge(1, 5, 5),
		Edge(2, 5, 6),
		Edge(2, 3, 5),
		Edge(3, 4, 9),
		Edge(3, 6, 3),
		Edge(4, 6, 7),
		Edge(5, 6, 2),
	};

	Kruskal kruskal = Kruskal(6, 8, graph);
	print(kruskal.find());

	std::vector<Edge> newGraph{
		Edge(1, 2, 6),
		Edge(1, 4, 5),
		Edge(1, 5, 4),
		Edge(2, 4, 1),
		Edge(2, 5, 2),
		Edge(2, 3, 5),
		Edge(2, 6, 3),
		Edge(3, 6, 4),
		Edge(4, 5, 2),
		Edge(5, 6, 4)
	};

	kruskal.changeGraph(6, 10, newGraph);
	print(kruskal.find());
}

