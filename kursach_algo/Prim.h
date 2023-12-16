#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "Edge.h"
#include "graphUtils.h"
#include "Kruskal.h"

# define INF 0x3f3f3f3f
using adj_list = std::vector<std::vector<std::pair<int, int>>>;

class Prim {
public:
	Prim(int vertices, int edges, adj_list graph);
	 std::vector<Edge> find();
private: 
	int _v, _e;
	adj_list _graph;
};

