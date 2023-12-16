#include "graphUtils.h"

int ostov_sum(const std::vector<Edge>& ostov) {
	int ostov_sum = 0;

	for (auto o : ostov) ostov_sum += o.weight();

	return ostov_sum;
}

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

	return { ostov, ostov_sum(ostov) };
}

result primFindFrom(std::string fileName) {
	std::ifstream input(fileName);
	int vertices, edges;

	input >> vertices; input >> edges;
	std::vector<std::vector<std::pair<int, int>>> graph(vertices + 1);

	if (input.is_open()) {

		int v1, v2, weight;

		while (input >> v1 >> v2 >> weight) {
			graph[v1 - 1].push_back({ v2 - 1, weight });
			graph[v2 - 1].push_back({ v1 - 1, weight });
		}
	}

	input.close();

	Prim prim = Prim(vertices, edges, graph);
	auto ostov = prim.find();


	return { ostov, ostov_sum(ostov)};
}

void print(const std::vector<Edge>& graph) {
	for (const auto& edge : graph) {
		std::cout << edge << std::endl;
	}
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