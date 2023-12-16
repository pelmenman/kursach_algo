#pragma once
#include <iostream>
#include <queue>
#include "Edge.h"
#include <algorithm>
#include <numeric>
#include "graphUtils.h"

class Kruskal {
public:
	Kruskal(int vertices, int edges, std::vector<Edge>& graph);
	std::vector<Edge> find();
	void changeGraph(int vertices, int edges, std::vector<Edge>& graph);
	int ostovSum();

private:
	int _v, _e, _ostov_sum;	
	std::vector<Edge> _graph;
	std::vector<int> _link = std::vector<int>(_v + 1);
	std::vector<int> _size = std::vector<int>(_v + 1, 1);

	int _helper_find(int x);
	bool _same(int a, int b);
	void _unite(int a, int b);
};

