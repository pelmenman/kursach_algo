#include "Prim.h"

using weightWithVertice = std::pair<int, int>;

Prim::Prim(int vertices, int edges, adj_list graph) : _v { vertices }, _e { edges }, _graph { graph } {}


int Prim::find() {
	std::priority_queue<weightWithVertice, std::vector<weightWithVertice>, std::greater<weightWithVertice>> queue;
	std::vector<bool> _visited(_v + 1, false);

	int ostov_sum = 0;
	queue.push({ 0, 1 });

	while (!queue.empty()) {
		auto item = queue.top(); queue.pop();

		auto node = item.second;
		auto weight = item.first;

		if (!_visited[node]) {
			ostov_sum += weight;
			_visited[node] = true;

			for (auto nextNode : _graph[node]) {
				if (!_visited[nextNode.second]) queue.push({ nextNode.first, nextNode.second });
			}
		}
	}

	return ostov_sum;
}