//============================================================================
// Name        : Graph.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
#include "GraphEdgeRep.h"

using namespace std;

int main() {
	int input;

	cout << "1. di-graph cycle example" << endl << "2. union find edge based example" << endl;
	cin >> input;

	switch (input)
	{
	case 1:
	{
		Graph g(4);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		//g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);
		g.printGraph();
		g.BFS(2);
		g.DFS(2);

		if(g.isCyclic())
		{
			cout << "cycle" << endl;
		}
		else
		{
			cout << "no cycle" << endl;
		}
		break;
	}

	case 2:
	{
		GraphEdgeRep g2(3,3);
		g2.addEdge(0,1);
		g2.addEdge(1,2);
		g2.addEdge(0,2);

		cout << "num edges: " << g2.getNumEdges() << " num vertices: " << g2.getNumVertices() << endl;

		g2.printGraph();

		if(g2.isCycle() == true)
		{
			cout << "cycle" << endl;
		}
		else
		{
			cout << "no cycle" << endl;
		}
		break;
	}
	}

	return 0;
}
