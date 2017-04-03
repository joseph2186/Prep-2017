//============================================================================
// Name        : Coursera.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Kosuraju strong connected component calculations
//============================================================================

#include <iostream>
#include <fstream>
#include "Graphs.h"

using namespace std;

int main() {
#if 0
	ifstream file("SCC.txt");
	int a,b;
	Graphs g(875714);

	if(!file.is_open())
		cout << "file open error" << endl;
	else
	{
		while((a < 4000) && (file >> a >> b))
		{
			g.addEdge(a,b);
			g.addRevEdge(a,b);
		}
	}

	g.printEdgesOfS(2);

	cin >> a;

	file.close();
#else
	Graphs g(9);
	g.addEdge(1,7);
	g.addEdge(4,1);
	g.addEdge(7,4);
	g.addEdge(7,9);
	g.addEdge(9,6);
	g.addEdge(6,3);
	g.addEdge(3,9);
	g.addEdge(6,8);
	g.addEdge(8,2);
	g.addEdge(2,5);
	g.addEdge(5,8);

	for(int i=1;i<=9;i++)
		g.printEdgesOfS(i);
	for(int i=1;i<=9;i++)
			g.printRevEdgesOfS(i);

	g.dfsLoop();
	g.printRank();

	g.dfsLoop2();
	g.printLeaders();
#endif
	return 0;
}
