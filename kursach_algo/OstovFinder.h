#pragma once
#include <iostream>
#include "Edge.h"
#include <vector>

template <typename Algorithm> 
class OstovFinder {
public:
	OstovFinder(Algorithm algorithm) : _algorithm { algorithm } {};
	std::vector<Edge> find() { return _algorithm.find(); }
	void changeAlgorithm(Algorithm algorithm) { _algorithm = algorithm; }
private:
	Algorithm _algorithm;
};

