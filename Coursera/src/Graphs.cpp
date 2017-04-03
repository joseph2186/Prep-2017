/*
 * Graphs.cpp
 *
 *  Created on: Apr 2, 2017
 *      Author: Joe
 */

#include <iostream>
#include "Graphs.h"
#include <vector>

using namespace std;

Graphs::Graphs() {
	cout << "No arg constructor" << endl;
	this->v = 0;
	this->adj = NULL;
	this->revAdj = NULL;
	this->vertex_rank = NULL;
}

Graphs::Graphs(int v){
	cout << "Number of vertices passed is " << v << endl;
	this->v = v;
	this->adj = new list<int>[v+1];
	this->revAdj = new list<int>[v+1];
	this->vertex_rank = new int[v+1];
}

void Graphs::addEdge(int s, int d){
	this->adj[d].push_back(s);
	this->revAdj[s].push_back(d);
}

void Graphs::addRevEdge(int s, int d){
	this->adj[d].push_back(s);
}

void Graphs::printEdgesOfS(int s){
	list<int>::iterator itr;
	cout << s << "->";
	for(itr=this->adj[s].begin();itr!=this->adj[s].end();itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
}

void Graphs::printRevEdgesOfS(int s){
	list<int>::iterator itr;
	cout << s << "->";
	for(itr=this->revAdj[s].begin();itr!=this->revAdj[s].end();itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
}

void Graphs::dfs(int s, int& t, bool visited[]){
	visited[s] = true;
	list<int>::iterator itr;
	for(itr = this->revAdj[s].begin() ; itr != this->revAdj[s].end() ; itr++)
	{
		if(visited[*itr] == false)
		{
			//cout << "call dfs from " << s << " to" << *itr << endl;
			dfs(*itr, t, visited);
		}
	}
	t++;
	//cout << "t is " << t << endl;
	this->vertex_rank[t] = s;
}

void Graphs::dfsLoop(){
	int t = 0;
	bool visited[this->v];

	for(int i=1;i<=this->v;i++)
	{
		visited[i] = false;
		this->vertex_rank[i] = 0;
	}

	//cout << "visited initialized" << endl;

	for(int i = this->v ; i > 0 ; i--)
	{
		if(visited[i] == false)
		{
			//cout << "call dfs for "  << i << endl;
			dfs(i, t, visited);
		}
	}
}

void Graphs::dfs2(int s, bool visited[]){
	visited[s] = true;
	list<int>::iterator itr;
	for(itr = this->adj[s].begin() ; itr != this->adj[s].end() ; itr++)
	{
		if(visited[*itr] == false)
		{
			//cout << "call dfs from " << s << " to" << *itr << endl;
			dfs2(*itr, visited);
		}
	}
}

void Graphs::dfsLoop2(){
	bool visited[this->v];

	for(int i=1;i<=this->v;i++)
	{
		visited[i] = false;
	}

	for(int i = this->v ; i > 0 ; i--)
	{
		if(visited[this->vertex_rank[i]] == false)
		{
			cout << "call dfs2 for "  << this->vertex_rank[i] << endl;
			dfs2(this->vertex_rank[i], visited);
			cout << "adding leader" << this->vertex_rank[i] <<endl;
			this->leader.push_back(this->vertex_rank[i]);
		}
	}
}

void Graphs::printRank(){
	for(int i=1 ; i<=this->v ; i++)
	{
		cout << "rank of " << i << " is " << this->vertex_rank[i] << endl;
	}
}

void Graphs::printLeaders(){
	vector<int>::iterator itr;
	cout << "Leaders:" << endl;
	for(itr = this->leader.begin() ; itr != this->leader.end() ; itr++)
	{
		cout << *itr << endl;
	}
}

Graphs::~Graphs() {
	delete this->adj;
	delete this->revAdj;
	delete this->vertex_rank;
}

