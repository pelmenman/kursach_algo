#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "Edge.h"
#include "graphUtils.h"
#include "Kruskal.h"

using adj_list = std::vector<std::vector<std::pair<int, int>>>;

class Prim {
public:
	Prim(int vertices, int edges, adj_list graph);
	void find();
private: 
	int _v, _e;
	adj_list _graph;
	//std::vector<int> _key = std::vector<int>(_v + 1, INFINITY);
	//std::vector<int> _parent = std::vector<int>(_v + 1, -1);
};

