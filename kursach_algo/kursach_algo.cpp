#include <iostream>
#include <vector>
#include "Edge.h"
#include <queue>
#include "graphUtils.h"
#include <functional>
#include <limits>
#include "Prim.h"

void print(std::priority_queue<Edge> q) {
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
}

int main() {
	//TEST 1
	auto k1_result = kruskalFindFrom("test1.txt");
	std::cout << k1_result.second << std::endl;

	auto p1_result = primFindFrom("test1.txt");
	std::cout << p1_result << std::endl;

	//TEST 2
	auto k2_result = kruskalFindFrom("test2.txt");
	std::cout << k2_result.second << std::endl;

	auto p2_result = primFindFrom("test2.txt");
	std::cout << p2_result << std::endl;
}

