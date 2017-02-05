//============================================================================
// Name        : CPPFileExample.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string str("My name is Joseph");
	char out[str.size()];

	ofstream ofile;
	ofile.open("file.txt");
	if ( ofile.is_open() )
	{
		ofile << str;
	}
	ofile.close();

	ifstream ifile;
	ifile.open("file.txt");
#if 0
	if ( ifile.is_open() )
	{
		while ( !ifile.eof() )
		{
			ifile >> out;
			cout << out;
		}
	}
#else
	if (ifile.is_open())
	{
		ifile.getline(out, str.size()+1);
		cout << out;
	}
#endif
	ifile.close();
	return 0;
}
