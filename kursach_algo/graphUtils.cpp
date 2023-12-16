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

int primFindFrom(std::string fileName) {
	std::ifstream input(fileName);
	int vertices, edges;

	input >> vertices; input >> edges;
	std::vector<std::vector<std::pair<int, int>>> graph(vertices + 1);

	if (input.is_open()) {

		int v1, v2, weight;

		while (input >> v1 >> v2 >> weight) {
			graph[v1].push_back({ weight, v2 });
			graph[v2].push_back({ weight, v1 });
		}
	}

	input.close();

	Prim prim = Prim(vertices, edges, graph);
	return prim.find();
}

void print(const std::vector<Edge>& graph) {
	for (const auto& edge : graph) {
		std::cout << edge << std::endl;
	}
	std::cout << std::endl;
}

bool compareByFirstVertice(const Edge& edge, const Edge& other) { return edge.v1() < other.v1(); }

bool compareByFirstVerticeAndWeight(const Edge& edge, const Edge& other) { 
	if (edge.v1() == other.v1()) {
		return edge.weight() < other.weight();
	}
	else {
		return edge.v1() < other.v1();
	}
}

bool compareByFirstVerticeAndWeightAsc(const Edge& edge, const Edge& other) { 
	if (edge.v1() == other.v1()) {
		return edge.weight() > other.weight();
	}
	else {
		return edge.v1() > other.v1();
	}
}

bool compareByWeightAsc(const Edge& edge, const Edge& other) { return edge.weight() > other.weight(); }