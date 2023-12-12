#include "Edge.h"

Edge::Edge() : _edge{ {0, 0}, 0 } {}
Edge::Edge(int v1, int v2, int weight) : _edge{ {v1, v2}, weight } {}

int Edge::v1() const { return _edge.first.first; }
void Edge::v1(int _v1) { _edge.first.first = _v1; }

int Edge::v2() const { return _edge.first.second; }
void Edge::v2(int _v2) { _edge.first.second = _v2; }

int Edge::weight() const { return _edge.second; }
void Edge::weight(int _weight) { _edge.second = _weight; }


std::ostream& operator << (std::ostream& os, const Edge& edge) { 
	return os << edge.v1() << " - " << edge.v2() << " " << edge.weight();
}

std::istream& operator >> (std::istream& in, Edge& edge) {
	int _v1, _v2, _weight;
	in >> _v1 >> _v2 >> _weight;

	edge.v1(_v1); edge.v2(_v2); edge.weight(_weight);
	
	return in;
}

bool operator < (const Edge& edge, const Edge& other) { return edge.weight() < other.weight(); }
bool operator > (const Edge& edge, const Edge& other) { return !(edge.weight() < other.weight()); }
bool operator == (const Edge& edge, const Edge& other) { return edge.weight() == other.weight(); }
bool operator != (const Edge& edge, const Edge& other) { return !(edge.weight() == other.weight()); }

bool compareByFirstVertice(Edge& edge, Edge& other) { return edge.v1() < other.v1(); }