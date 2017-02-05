//============================================================================
// Name        : SmartPointerExample.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SmartPointer.h"

using namespace std;

int main() {
	SmartPointer<string> p(new string("Joseph Bernard"));
	{
		SmartPointer<string> q = p;
		cout << *q << endl;
	}
	cout << *p << endl;
	return 0;
}
