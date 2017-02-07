/*
 * GraphEdgeRep.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: Joe
 */

#include<iostream>
#include "GraphEdgeRep.h"
using namespace std;

GraphEdgeRep::GraphEdgeRep() {
	cout << "constructor with no args" << endl;

}

GraphEdgeRep::GraphEdgeRep(int v, int e):V(v), E(e){
	cout << "constructor with args" << endl;
	this->Edge = new struct edge[this->E];
	this->edge_count = 0;
	this->parent = new int[this->V];

	for(int i=0;i<this->V;i++)
	{
		this->parent[i] = -1;
	}
}

GraphEdgeRep::GraphEdgeRep(GraphEdgeRep& rhs){
	cout << "copy constructor" << endl;
	this->E = rhs.E;
	this->Edge = rhs.Edge;
	this->V = rhs.V;
	this->edge_count = rhs.edge_count;
}

void GraphEdgeRep::addEdge(int x, int y){
	if((this->edge_count)+1 > this->E)
	{
		cout << "ERROR: edges exceeded initial value" << endl;
		return;
	}
	if(x > V-1)
	{
		cout << "ERROR: src exceeded the initial value of number of vertices" << endl;
		return;
	}
	if(y > V-1)
	{
		cout << "ERROR: dest exceeded the initial value of number of edges" << endl;
		return;
	}

	this->Edge[this->edge_count].src = x;
	this->Edge[this->edge_count].dest = y;
	this->edge_count++;

	cout << "src:" << this->Edge[this->edge_count-1].src << " dest:" << this->Edge[this->edge_count-1].dest << " edge count:" << this->edge_count << endl;
}

int GraphEdgeRep::getNumVertices(){
	return this->V;
}

int GraphEdgeRep::getNumEdges(){
	return this->edge_count;
}

void GraphEdgeRep::printGraph(){
	for(int i=0;i<this->edge_count;i++)
	{
		cout << this->Edge[i].src << "->" << this->Edge[i].dest << endl;
	}
}

int GraphEdgeRep::find(int i)
{
	if (this->parent[i] == -1)
		return i;
	return find(this->parent[i]);
}

void GraphEdgeRep::union_find(int u, int v)
{
	int parent_u = find(u);
	int parent_v = find(v);
	parent[parent_u]=parent_v;
}

bool GraphEdgeRep::isCycle()
{
	for(int i=0;i<this->edge_count;i++)
	{
		int x = find(this->Edge[i].src);
		int y = find(this->Edge[i].dest);

		if (x == y)
			return true;

		union_find(x,y);
	}
	return false;
}

GraphEdgeRep::~GraphEdgeRep() {
	cout << "destructor" << endl;
	delete[] this->Edge;
	delete[] this->parent;
}

