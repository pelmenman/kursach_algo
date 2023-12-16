#include <iostream>
#include <vector>
#include "Edge.h"
#include <queue>
#include "graphUtils.h"
#include <functional>
#include <limits>
#include "Prim.h"

void print(std::priority_queue<Edge> q) {
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
}

int main() {
	auto k1_result = kruskalFindFrom("test1.txt");
	print(k1_result.first);
	std::cout << k1_result.second << std::endl;

	//auto k2_result = kruskalFindFrom("test2.txt");
	//std::cout << k2_result.second << std::endl;

	/*std::vector<Edge> graph{
		Edge(2, 3, -10),
		Edge(1, 2, 5),
		Edge(2, 4, 2),
		Edge(1, 3, 1)
	};

	std::vector<std::pair<int, int>> adj[2];
	adj[0].push_back({1, 1});
	adj[0].push_back({1, 2});
	adj[0].push_back({1, 4});
	adj[1].push_back({7, 4});

	for (auto u : adj[0]) {
		std::cout << u.first << " " << u.second << std::endl;
	}*/

	std::ifstream input("test1.txt");
	int vertices, edges;

	input >> vertices; input >> edges;
	std::vector<std::vector<std::pair<int, int>>> graph(vertices + 1);

	if (input.is_open()) {

		int v1, v2, weight;

		while (input >> v1 >> v2 >> weight) {
			graph[v1].push_back({ weight, v2 });
		}
	}

	input.close();

	Prim prim = Prim(vertices, edges, graph);
	prim.find();
	/*std::cout << "================================================\n";
	print(result.first);
	std::cout << result.second << std::endl;

	std::priority_queue<Edge, std::vector<Edge>, std::function<bool(Edge, Edge)>> q(compareByFirstVerticeAndWeightAsc);

	q.push(Edge(4, 1, 900));
	q.push(Edge(4, 1, 10));
	q.push(Edge(2, 7, 23));
	q.push(Edge(1, 4, -22));
	q.push(Edge(7, 8, 40));

	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}*/

}

