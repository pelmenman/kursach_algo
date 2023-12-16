#include "Kruskal.h"

Kruskal::Kruskal(int vertices, int edges, std::vector<Edge>& graph) : _v{ vertices }, _e{ edges }, _graph{ graph } {
	std::iota(_link.begin(), _link.end(), 0);
}

int Kruskal::_helper_find(int x) {
 	while (x != _link[x]) x = _link[x];
	return x;
}

bool Kruskal::_same(int a, int b) { return _helper_find(a) == _helper_find(b); }

void Kruskal::_unite(int a, int b) {
	a = _helper_find(a);
	b = _helper_find(b);

	if (_size[a] < _size[b]) std::swap(a, b);

	_size[a] += _size[b];
	_link[b] = a;
}

std::vector<Edge> Kruskal::find() {
	std::vector<Edge> ostov;
	std::sort(_graph.begin(), _graph.end());
	
	for (auto g : _graph) {
		if (!_same(g.v1(), g.v2())) {
			_unite(g.v1(), g.v2());

			ostov.push_back(g);
			//_ostov_sum += g.weight();
		}
	}

	std::sort(ostov.begin(), ostov.end(), compareByFirstVertice);
	return ostov; 
}

void Kruskal::changeGraph(int vertices, int edges, std::vector<Edge>& graph) {
	_v = vertices;
	_e = edges;
	_graph = graph;
	//_ostov_sum = 0;
	_link = std::vector<int>(_v + 1);
	std::iota(_link.begin(), _link.end(), 0);
	_size = std::vector<int>(_v + 1, 1);
}

//int Kruskal::ostovSum() { return _ostov_sum; }
