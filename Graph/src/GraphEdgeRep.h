/*
 * GraphEdgeRep.h
 *
 *  Created on: Feb 6, 2017
 *      Author: Joe
 */

#ifndef GRAPHEDGEREP_H_
#define GRAPHEDGEREP_H_
#include <iostream>

class GraphEdgeRep {
private:
	struct edge
	{
		int src, dest;
	};

	int V;
	int E;
	int edge_count;

	struct edge *Edge;
	int *parent;

public:
	GraphEdgeRep();
	GraphEdgeRep(int v, int e);
	GraphEdgeRep(GraphEdgeRep& rhs);
	void addEdge(int src, int dest);
	int getNumVertices();
	int getNumEdges();
	void printGraph();

	//union-find
	int find(int i);
	void union_find(int u, int v);

	bool isCycle();

	virtual ~GraphEdgeRep();
};

#endif /* GRAPHEDGEREP_H_ */
