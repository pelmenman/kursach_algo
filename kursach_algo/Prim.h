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
	int find();
private: 
	int _v, _e;
	adj_list _graph;
};

