#include "Prim.h"

using weightWithVertice = std::pair<int, int>;

Prim::Prim(int vertices, int edges, adj_list graph) : _v { vertices }, _e { edges }, _graph { graph } {}


//int Prim::find() {
//	std::priority_queue<weightWithVertice, std::vector<weightWithVertice>, std::greater<weightWithVertice>> queue;
//	std::vector<bool> _visited(_v + 1, false);
//
//	int ostov_sum = 0;
//	queue.push({ 0, 1 });
//
//	while (!queue.empty()) {
//		auto item = queue.top(); queue.pop();
//
//		auto node = item.second;
//		auto weight = item.first;
//
//		if (!_visited[node]) {
//			ostov_sum += weight;
//			_visited[node] = true;
//
//			for (auto nextNode : _graph[node]) {
//				if (!_visited[nextNode.second]) queue.push({ nextNode.first, nextNode.second });
//			}
//		}
//	}
//
//	return ostov_sum;
// }

std::vector<Edge> Prim::find() {
	std::vector<int> _key (_v, INF);
	std::vector<int> _parent (_v, -1);
	std::vector<bool> _visited(_v, false);
	std::priority_queue<weightWithVertice, std::vector<weightWithVertice>, std::greater<weightWithVertice>> q;
	std::vector<Edge> ostov;

	q.push({ 0, 0 });
	_key[0] = 0;

	while (!q.empty()) {
		auto node = q.top().second; q.pop();

		if (_visited[node]) continue;

		_visited[node] = true;

		for (auto nextNode : _graph[node]) {
			auto v = nextNode.first;
			auto weight = nextNode.second;

			if (!_visited[v] && _key[v] > weight) {
				_key[v] = weight;
				q.push({ _key[v], v });
				_parent[v] = node;
			}
		}
	}
	
	for (int i = 1; i < _v; i++) ostov.push_back(Edge(_parent[i] + 1, i + 1, _key[i]));
	std::sort(ostov.begin(), ostov.end(), compareByFirstVertice);

	return ostov;
}