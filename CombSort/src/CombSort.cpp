//============================================================================
// Name        : CombSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int getNextGap(int gap)
{
	gap = (gap*10)/13;

	if (gap < 1)
		return 1;
	return gap;
}

void combsort(int arr[], int n)
{
	int gap = n;
	bool swapped = true;

	while(gap!=1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;
		for(int i=0;i<n-gap;i++)
		{
			if(arr[i] > arr[i+gap])
			{
				swap(arr[i], arr[i+gap]);
				swapped = true;
			}
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

		combsort(arr, n);

		cout << "array after combsort" << endl;
		printarray(arr,n);
		delete[] arr;
		return 0;
}
