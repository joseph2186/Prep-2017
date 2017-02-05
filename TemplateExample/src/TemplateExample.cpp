//============================================================================
// Name        : TemplateExample.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PairTemplate.h"
using namespace std;

template <typename T> void swap_i(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	swap_i(a,b);

	PairTemplate<int> pair(1,2);
	cout << "first =" << pair.getFirst() << "second =" << pair.getSecond() << endl;
	cout << "a=" << a << "b=" << b << endl;
	return 0;
}
