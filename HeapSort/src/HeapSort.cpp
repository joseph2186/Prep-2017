//============================================================================
// Name        : HeapSort.cpp
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

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;

	if (l<n && arr[l]>arr[largest])
	{
		largest = l;
	}

	if (r<n && arr[r]>arr[largest])
	{
		largest = r;
	}

	if (largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapsort(int arr[], int n)
{
	//bottom up heapify
	for(int i = n/2-1 ; i >=0 ; i--)
	{
		heapify(arr, n, i);
	}

	cout << "array after heapify" << endl;

	printarray(arr, n);

	//heapify and remove the largest
	for(int i = n-1 ; i >= 0 ; i--)
	{
		swap(arr[0],arr[i]);

		heapify(arr,i,0);
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

	heapsort(arr,n);

	cout << "array after heapsort" << endl;
	printarray(arr,n);
	delete[] arr;
	return 0;
}
