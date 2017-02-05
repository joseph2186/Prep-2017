//============================================================================
// Name        : CountingSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define RANGE 9

void printarray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void countingsort(int arr[], int n)
{
	int output[n] = {0};
	int countarray[RANGE] = {0};
	printarray(countarray, RANGE);
	//step 1 - set the count
	for ( int i = 0 ; i < n ; i++ )
	{
		++countarray[arr[i]];
	}

	cout << "counting array" << endl;

	printarray(countarray, RANGE);

	//step 2 - add consecutive elements from the counting array
	for (int i = 1 ; i<=RANGE ; i++)
	{
		countarray[i] += countarray[i-1];
	}

	cout << "counting array after the addition" << endl;

	printarray(countarray, RANGE);

	//step 3 - output
	for (int i=0 ; i<n ; i++)
	{
		output[countarray[arr[i]]-1] = arr[i];
		--countarray[arr[i]];
	}

	for (int i=0 ; i<n ; i++)
	{
		arr[i] = output[i];
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

	countingsort(arr, n);

	cout << "array after countsort" << endl;
	printarray(arr,n);
	delete[] arr;
	return 0;
}
