//============================================================================
// Name        : BucketSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketsort(float arr[], int n)
{
	vector<float> bucket[n];

	for (int i=0 ; i<n ; i++)
	{
		int bucketID = arr[i]*10;
		bucket[bucketID].push_back(arr[i]);
	}

	for (int i=0 ; i<n ; i++)
	{
		sort(bucket[i].begin(), bucket[i].end());
	}

	int index = 0;
	for(int i=0;i<n; i++)
	{
		for(int j=0;j<bucket[i].size();j++)
		{
			arr[index++] = bucket[i][j];
		}
	}
}

void printarray(float arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	float *arr;
	int n;
	cout << "enter the number of elements" << endl;
	cin >> n;

	arr = new float[n];

	cout << "input the elements of the array" << endl;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}

	cout << "input array" << endl;
	printarray(arr,n);

	bucketsort(arr, n);

	cout << "array after bucketsort" << endl;
	printarray(arr,n);
	delete[] arr;
	return 0;
}
