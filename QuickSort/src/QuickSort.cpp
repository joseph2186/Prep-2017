//============================================================================
// Name        : QuickSort.cpp
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

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low -1;
	for (int j = low ; j <= high-1 ; j++)
	{
		if (arr[j]<pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
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

	quicksort(arr, 0, n-1);

	cout << "array after heapsort" << endl;
	printarray(arr,n);
	delete[] arr;
	return 0;
}
