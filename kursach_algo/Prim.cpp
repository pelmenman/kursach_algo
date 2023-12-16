#include "Prim.h"

Prim::Prim(int vertices, int edges, adj_list graph) : _v { vertices }, _e { edges }, _graph { graph } {}

using weightWithVertice = std::pair<int, int>;

template<class Queue>
void print(Queue q) {
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
}

//void Prim::find() {
//	std::vector<bool> _visited(_v+1, false);
//	std::vector<int> _key(_v+1, INFINITY);
//	std::priority_queue<weightWithVertice, std::vector<weightWithVertice>, std::greater<weightWithVertice>> queue;
//	//std::priority_queue<Edge> queue;
//	std::vector<Edge> ostov;
//	int ostov_sum = 0;
//
//	_visited[1] = true;
//	_key[1] = 0;
//	queue.push({0, 1});
//	//for (auto v2 : _graph[v1]) queue.push(Edge(v1, v2.first, v2.second));
//	//std::cout << "=======================\n";
//	//print(queue);
//	//std::cout << "=======================\n";
//
//	while (!queue.empty()) {
//		auto v1 = queue.top().second; queue.pop();
//
//		_visited[v1] = true;
//			
//		for (auto g : _graph[v1]) {
//			auto v2 = g.second;
//			auto weight_uv = _key[v1] - _key[v2];
//
//			if (!_visited[v2] && _key[v2] > weight_uv) {
//				queue.push({ weight_uv,v2 });
//				_key[v2] = weight_uv;
//				ostov.push_back(Edge(v1, v2, weight_uv));
//			}
//		}
//	}
//
//
//	for (auto g : ostov) {
//		std::cout << g << std::endl;
//	}
//
//}


void Prim::find() {
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

	std::cout << ostov_sum << std::endl;
}