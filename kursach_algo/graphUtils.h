#pragma once
#include <iostream>
#include "Edge.h"
#include "Kruskal.h"
#include <fstream>
#include <vector>

using result = std::pair<std::vector<Edge>, int>;

result kruskalFindFrom(std::string fileName);

void print(const std::vector<Edge>& graph);

bool compareByFirstVertice(const Edge& edge, const Edge& other);

bool compareByFirstVerticeAndWeight(const Edge& edge, const Edge& other);

bool compareByFirstVerticeAndWeightAsc(const Edge& edge, const Edge& other);

bool compareByWeightAsc(const Edge& edge, const Edge& other);