//============================================================================
// Name        : SmallestConstructibleValue.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SmallestNonConstructibleValue(vector<int>& a)
{
	int maxConstructibleVal = 0;

	/* Sort can be used on a vector */
	sort(a.begin(), a.end());

	/* iterates throught the vector */

	for(int A:a)
	{
		if(A > maxConstructibleVal + 1)
		{
			break;
		}
		maxConstructibleVal += A;
	}
	return maxConstructibleVal+1;
}

int main() {
	vector<int> a;
	a. push_back(12);
	a.push_back(2);
	a.push_back(1);
	a.push_back(15);
	a.push_back(2);
	a.push_back(4);

	cout << "smallest constructible val = " << SmallestNonConstructibleValue(a) << endl;
	return 0;
}
