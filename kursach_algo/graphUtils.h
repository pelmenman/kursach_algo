#pragma once
#include <iostream>
#include "Edge.h"
#include "Kruskal.h"
#include <fstream>
#include <vector>

using result = std::pair<std::vector<Edge>, int>;

result kruskalFindFrom(std::string fileName);

void print(const std::vector<Edge>& graph);
