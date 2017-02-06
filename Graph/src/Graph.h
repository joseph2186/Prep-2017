/*
 * Graph.h
 *
 *  Created on: Feb 5, 2017
 *      Author: Joe
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
using namespace std;

class Graph {
private:
	//Number of vertices
	int v;
	list<int> *adj;

public:
	//constructors
	Graph();
	Graph(int v);
	Graph(Graph& rhs);

	void addEdge(int src, int dest);

	void printGraph();

	void BFS(int s);

	void DFSUtil(int i, bool visited[]);
	void DFS(int s);

	int getNumVertices();

	//destructor
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
