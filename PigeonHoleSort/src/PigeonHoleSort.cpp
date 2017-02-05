//============================================================================
// Name        : PigeonHoleSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void pigeonholesort(int arr[], int n)
{
	int min,max;

	min = max = arr[0];
	for(int i=1 ; i<n ; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max-min+1;

	vector<int> hole[range];

	for (int i=0;i<n;i++)
	{
		hole[arr[i]-min].push_back(arr[i]);
	}

	int idx = 0;
	for(int i=0;i<n;i++)
	{
		vector<int>::iterator itr;
		for(itr=hole[i].begin();itr!=hole[i].end();++itr)
		{
			arr[idx++]=*itr;
		}
	}
}
int main() {
	int *arr;
			int n;
			cout << "enter the number of elements" << endl;
			cin >> n;

			arr = new int[n];

			cout << "input the elements of the array" << endl;
			for(int i = 0 ; i < n ; i++)
			{
				cin >> arr[i];
			}

			cout << "input array" << endl;
			printarray(arr,n);

			pigeonholesort(arr, n);

			cout << "array after pigeon hole sort" << endl;
			printarray(arr,n);
			delete[] arr;
			return 0;
}
