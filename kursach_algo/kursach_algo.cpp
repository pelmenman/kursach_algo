#include <iostream>
#include <vector>
#include "Edge.h"
#include "graphUtils.h"

int main() {
	auto k1_result = kruskalFindFrom("test1.txt");
	print(k1_result.first);
	std::cout << k1_result.second << std::endl;

	auto k2_result = kruskalFindFrom("test2.txt");
	std::cout << k2_result.second << std::endl;
}

