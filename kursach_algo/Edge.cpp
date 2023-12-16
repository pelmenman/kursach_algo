#include "Edge.h"

Edge::Edge() : _edge { {0, 0}, 0 } {}
Edge::Edge(int vertice1, int vertice2, int weight) : _edge { {vertice1, vertice2}, weight } {}

int Edge::v1() const { return _edge.first.first; }
void Edge::v1(int newFirstVertice) { _edge.first.first = newFirstVertice; }

int Edge::v2() const { return _edge.first.second; }
void Edge::v2(int newSecondVertice) { _edge.first.second = newSecondVertice; }

int Edge::weight() const { return _edge.second; }
void Edge::weight(int newWeight) { _edge.second = newWeight; }


std::ostream& operator << (std::ostream& os, const Edge& edge) { 
	return os << edge.v1() << " - " << edge.v2() << " " << edge.weight();
}

std::istream& operator >> (std::istream& in, Edge& edge) {
	int _v1, _v2, _weight;
	in >> _v1 >> _v2 >> _weight;

	edge.v1(_v1); edge.v2(_v2); edge.weight(_weight);
	
	return in;
}

bool operator == (const Edge& edge, const Edge& other) { return edge.weight() == other.weight(); }
bool operator != (const Edge& edge, const Edge& other) { return !(edge == other); }
bool operator < (const Edge& edge, const Edge& other) { return edge.weight() < other.weight(); }
bool operator > (const Edge& edge, const Edge& other) { return !(edge < other) && (edge != other); }
