//============================================================================
// Name        : ReadSpaceDelimitedInt.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define DEBUG 1
int main() {
	cout << "Read Kragers min cut" << endl;

	string str[201];
	vector<string> strTokens[200];
	int i = 0;
	ifstream fileIF;
	int V = 200;
	int E = 0;

	int e;

	fileIF.open("kargerMinCut.txt");

	while (getline(fileIF, str[i++]));

	if (DEBUG == 1)
		cout << str[0] << endl;

	for( i=0 ; i<200 ; i++)
	{

		istringstream iss(str[i]);

		copy(istream_iterator<string>(iss),
		     istream_iterator<string>(),
		     back_inserter(strTokens[i]));
	}

	if (DEBUG == 1)
	{
		vector<string>::iterator itr;
		for(itr = strTokens[199].begin();itr!=strTokens[199].end();itr++)
		{
			stringstream(*itr) >> e;
			cout << e << endl;
		}
	}

	for( i=0 ; i<200 ; i++ )
	{
		vector<string>::iterator itr;
		for(itr = strTokens[i].begin();itr!=strTokens[i].end();itr++)
		{
			E++;
		}
	}

	E = E - 200;
	cout << "v = " << V << " e= " << E << endl;

	fileIF.close();

	getchar();
	return 0;
}
