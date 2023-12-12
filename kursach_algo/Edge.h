#pragma once
#include <utility>
#include <iostream>

class Edge {
public:
	Edge();
	Edge(int v1, int v2, int weight);

	int v1() const;
	void v1(int _v1);

	int v2() const;
	void v2(int _v2);

	int weight() const;
	void weight(int _weight);

private:
	std::pair<std::pair<int, int>, int> _edge;
};

std::ostream& operator << (std::ostream& os, const Edge& edge);
std::istream& operator >> (std::istream& is, Edge& edge);

bool operator < (const Edge& edge, const Edge& other);
bool operator > (const Edge& edge, const Edge& other);
bool operator == (const Edge& edge, const Edge& other);
bool operator != (const Edge& edge, const Edge& other);
bool compareByFirstVertice(Edge& edge, Edge& other);