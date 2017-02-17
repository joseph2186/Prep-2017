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
#include <ctime>

using namespace std;

int main() {
	int input;

	cout << "1. di-graph cycle example" << endl << "2. union find edge based example" << endl << "3. topological sort" << endl << "4. bipartite example" << endl;
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
		GraphEdgeRep g2(10,10);
		g2.addEdge(0,4);
		g2.addEdge(4,9);
		g2.addEdge(9,5);
		g2.addEdge(4,3);
		g2.addEdge(1,3);
		g2.addEdge(2,3);
		g2.addEdge(6,9);
		g2.addEdge(7,6);
		g2.addEdge(6,8);

		//edge causing the cycle
		g2.addEdge(1,2);

		cout << "num edges: " << g2.getNumEdges() << " num vertices: " << g2.getNumVertices() << endl;

		g2.printGraph();

		int start_s=clock();
		if(g2.isCycle() == true)
		{
			cout << "cycle no opt" << endl;
		}
		else
		{
			cout << "no cycle no opt" << endl;
		}
		int stop_s=clock();
		cout << "time no opt: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;

		start_s=clock();
		if(g2.isCycleOpt() == true)
		{
			cout << "cycle opt" << endl;
		}
		else
		{
			cout << "no cycle opt" << endl;
		}
		stop_s=clock();
		cout << "time opt: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
		break;
	}
	case 3:
	{
		Graph g3(6);
		g3.addEdge(5,2);
		g3.addEdge(5,0);
		g3.addEdge(4,0);
		g3.addEdge(4,1);
		g3.addEdge(2,3);
		g3.addEdge(3,1);

		g3.topologicalSort();
		break;
	}

	case 4:
	{
		Graph g4(4);
		g4.addEdge(0,1);
		g4.addEdge(0,3);
		g4.addEdge(2,1);
		g4.addEdge(2,3);

		//edge to fail bipartite
		g4.addEdge(0,2);

		cout << "is bipartite " << g4.isBipartite() << endl;
	}
	}

	return 0;
}
