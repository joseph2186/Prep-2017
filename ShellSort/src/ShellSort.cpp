//============================================================================
// Name        : ShellSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void shellsort(int arr[], int n)
{
	for (int gap = n/2 ; gap > 0 ; gap /= 2)
	{
		for(int i=gap ; i<n; i++)
		{
			int temp = arr[i];
			int j;
			for (j=i ; j>=gap && arr[j-gap] > temp ; j -= gap)
			{
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

int main() {
	int *arr;
		int n;
		cout << "enter the number of elements" <<  endl;
		cin >> n;

		arr = new int[n];

		cout << "input the elements of the array" << endl;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> arr[i];
		}

		cout << "input array" << endl;
		printarray(arr,n);

		shellsort(arr, n);

		cout << "array after shellsort" << endl;
		printarray(arr,n);
		delete[] arr;
		return 0;
}
