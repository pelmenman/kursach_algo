#include "graphUtils.h"

result kruskalFindFrom(std::string fileName) {
	std::ifstream input(fileName);
	int vertices, edges;

	input >> vertices; input >> edges;
	std::vector<Edge> graph;

	if (input.is_open()) {

		int v1, v2, weight;

		while (input >> v1 >> v2 >> weight) {
			graph.push_back(Edge(v1, v2, weight));
		}
	}

	input.close();

	Kruskal kruskal = Kruskal(vertices, edges, graph);
	auto ostov = kruskal.find();

	return { ostov, kruskal.ostovSum() };
}

void print(const std::vector<Edge>& graph) {
	for (const auto& edge : graph) {
		std::cout << edge << std::endl;
	}
	std::cout << std::endl;
}