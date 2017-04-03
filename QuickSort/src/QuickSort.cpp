//============================================================================
// Name        : QuickSort.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include <string>
using namespace std;

long long int countl, counth, countm;

int getNumLines(string fileName)
{
	ifstream file;
	int i = 0;
	string line;
	file.open(fileName.c_str());
	while(getline(file, line))
	{
		i++;
	}

	file.close();
	//cout << "i=" << i << endl;
	return i;
}

void readFile(string fileName, int arr[])
{
	ifstream file;
	int i = 0;
	file.open(fileName.c_str());
	while(file >> arr[i])
	{
		i++;
	}

	file.close();
	//cout << "i=" << i << endl;
}

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

int partition_h(int arr[], int low, int high)
{
	swap(arr[high], arr[low]);
	int pivot = arr[low];
	int i = low+1;
	for (int j = low+1 ; j <= high ; j++)
	{
		if (arr[j]<pivot)
		{
			//if(i!=j)
			{
			  swap(arr[i], arr[j]);
			  i++;
			}
		}
	}
	swap(arr[i-1], arr[low]);
	return i-1;
}

void quicksort_h(int arr[], int low, int high)
{
	if(low<high)
	{
		counth += high-low;
		int pivot = partition_h(arr, low, high);
		quicksort_h(arr, low, pivot-1);
		quicksort_h(arr, pivot+1, high);
	}
}

int partition_l(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low+1;
	for (int j = low+1 ; j <= high ; j++)
	{
		if (arr[j]<pivot)
		{
			//if(i!=j)
			{
			  swap(arr[i], arr[j]);
			  i++;
			}
		}
	}
	swap(arr[i-1], arr[low]);
	return i-1;
}

void quicksort_l(int arr[], int low, int high)
{
	if(low<high)
	{
		countl += high-low;
		int pivot = partition_l(arr, low, high);
		quicksort_l(arr, low, pivot-1);
		quicksort_l(arr, pivot+1, high);
	}
}

int partition_m(int arr[], int low, int high)
{
	int middle = ( low + high ) / 2;
	int pivot_id = 0;
	if (arr[low] > arr[middle]) {
	  if (arr[middle] > arr[high]) {
	    pivot_id = middle;
	  } else if (arr[low] > arr[high]) {
	    pivot_id = high;
	  } else {
	    pivot_id = low;
	  }
	} else {
	  if (arr[low] > arr[high]) {
	    pivot_id = low;
	  } else if (arr[middle] > arr[high]) {
	    pivot_id = high;
	  } else {
	    pivot_id = middle;
	  }
	}
	swap(arr[pivot_id], arr[low]);
	int pivot = arr[low];
	int i = low+1;
	for (int j = low+1 ; j <= high ; j++)
	{
		if (arr[j]<pivot)
		{
			//if(i!=j)
			{
			  swap(arr[i], arr[j]);
			  i++;
			}
		}
	}
	swap(arr[i-1], arr[low]);
	return i-1;
}

void quicksort_m(int arr[], int low, int high)
{
	if(low<high)
	{
		countm += high-low;
		int pivot = partition_m(arr, low, high);
		quicksort_m(arr, low, pivot-1);
		quicksort_m(arr, pivot+1, high);
	}
}

int main() {
	int *arr;
	int n;
#if 0
	cout << "enter the number of elements" << endl;
	cin >> n;
#else
	n = getNumLines("QuickSortData.txt");
#endif
	arr = new int[n];
#if 0
	cout << "input the elements of the array" << endl;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}
#else
	cout << "input array" << endl;
	readFile("QuickSortData.txt", arr);
	//printarray(arr,n);

	countl = counth = countm = 0;

	quicksort_l(arr, 0, n-1);

	//cout << "array after heapsort" << endl;
	//printarray(arr,n);

	cout << endl << "countl = " << countl;

	readFile("QuickSortData.txt", arr);
	//printarray(arr,n);

	quicksort_m(arr, 0, n-1);

	//cout << "array after heapsort" << endl;
	//printarray(arr,n);

	cout << endl << "countm = " << countm;

	readFile("QuickSortData.txt", arr);
	//printarray(arr,n);

	quicksort_h(arr, 0, n-1);

	//cout << "array after heapsort" << endl;
	//printarray(arr,n);

	cout << endl << "counth = " << counth;
	delete[] arr;
#endif
	return 0;
}
