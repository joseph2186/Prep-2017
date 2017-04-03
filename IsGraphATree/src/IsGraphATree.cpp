//============================================================================
// Name        : IsGraphATree.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

class graph
{
private:
	int U;
	int V;
	list<int> *adj;
public:
	graph(){
		cout << "No arg constructor" << endl;
	}

	graph(int v):V(v){
		this->adj = new list<int>[V];
		cout << "Number of vertices = " << V << endl;
	}

	graph(graph& G){
		cout << "copy constructor" << endl;
		this->U = G.U;
		this->V = G.V;
		this->adj = G.adj;
	}

	void addEdge(int src, int dest)
	{
		if ( src >= this->V )
			cout << "src entered in error " << src << endl;
		else if ( dest >= this->V)
			cout << "dest entered in error " << dest << endl;
		else
		{
			this->adj[src].push_back(dest);
			cout << "edge added " << src << "->" << dest << endl;
		}
	}

	bool IsCycleUtil(int i, bool visited[], bool recstack[])
	{
		visited[i] = true;
		recstack[i] = true;

		list<int>::iterator itr;
		for(itr = this->adj[i].begin() ; itr != this->adj[i].end() ; itr++)
		{
			int v = *itr;
			if(visited[v] != true)
				if(IsCycleUtil(v, visited, recstack))
					return true;
			else if(recstack[v] == true)
				return true;
		}
		recstack[i] = false;
		return false;
	}

	bool isCycle()
	{
		bool visited[this->V];
		bool recstack[this->V];

		for(int i=0;i<this->V;i++)
		{
			visited[i] = false;
			recstack[i] = false;
		}

		for(int i=0;i<this->V;i++)
			if(IsCycleUtil(i, visited, recstack))
				return true;

		return false;
	}

	void DFSUtil(int i, bool visited[])
	{
		visited[i] = true;

		list<int>::iterator itr;
		for(itr = this->adj[i].begin() ; itr!=this->adj[i].end();itr++)
		{
			if(visited[*itr] != true)
				DFSUtil(*itr, visited);
		}
	}

	bool isTree()
	{
		if(isCycle())
		{
			cout << "there is a cycle" << endl;
			return false;
		}

		bool visited[this->V];

		for (int i = 0 ; i < this->V ; i++)
			visited[i] = false;

		DFSUtil(0, visited);

		for(int i=0;i<this->V;i++)
		{
			if(visited[i]!= true)
			{
				cout << "edge " << i << "not connected from the source" << endl;
				return false;
			}
		}

		return true;
	}
};

int main() {
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
	return 0;
}
