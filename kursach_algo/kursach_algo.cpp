#include <iostream>
#include <vector>
#include "Edge.h"
#include <queue>
#include "graphUtils.h"
#include <functional>
#include <limits>
#include "Prim.h"

int main() {
	//TEST 1
	std::cout << "TEST1: KRUSKAL\n";
	auto k1_result = kruskalFindFrom("test1.txt");
	
	print(k1_result.first);
	std::cout << std::endl;

	std::cout << "WEIGHT:\n";
	std::cout << k1_result.second << std::endl;
	std::cout << std::endl;

	std::cout << "TEST1: PRIM\n";
	auto p1_result = primFindFrom("test1.txt");
	
	print(p1_result.first);
	std::cout << std::endl;

	std::cout << "WEIGHT:\n";
	std::cout <<  p1_result.second << std::endl;
	std::cout << std::endl;

	//TEST 2
	std::cout << "TEST2: KRUSKAL\n";
	auto k2_result = kruskalFindFrom("test2.txt");
	std::cout << k2_result.second << std::endl;

	std::cout << std::endl;

	std::cout << "TEST2: PRIM\n";
	auto p2_result = primFindFrom("test2.txt");
	std::cout << p2_result.second << std::endl;
}

