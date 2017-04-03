/*
 * Graphs.h
 *
 *  Created on: Apr 2, 2017
 *      Author: Joe
 */

#ifndef GRAPHS_H_
#define GRAPHS_H_

#include <list>
#include <vector>

using namespace std;

class Graphs {
private:
	int v;
	list<int> *adj;
	list<int> *revAdj;
	int *vertex_rank;
	vector<int> leader;

public:
	Graphs();
	Graphs(int v);
	void addEdge(int s, int d);
	void addRevEdge(int s, int d);

	void dfsLoop();
	void dfs(int s, int& t, bool visited[]);
	void printRank();

	void dfsLoop2();
	void dfs2(int s, bool visited[]);

	void printEdgesOfS(int s);
	void printRevEdgesOfS(int s);
	void printLeaders();

	virtual ~Graphs();
};

#endif /* GRAPHS_H_ */
