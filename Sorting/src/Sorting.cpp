//============================================================================
// Name        : Sorting.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include <string>
using namespace std;

void insertion_sort(long long int arr[], int size)
{
	for (int i=1 ; i<size ; i++)
	{
		int j = i-1;
		int key = arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


void merge(long long int arr[], int l, int m, int r)
{

	int n1 = m-l+1;
	int n2 = r-m;
	long long int l1[n1], l2[n2];

	int i, j, k;

	for(i=0;i<n1;i++)
	{
		l1[i] = arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		l2[j] = arr[m+j+1];
	}

	i=j=0;
	k=l;

	while(i<n1&&j<n2)
	{
		if(l1[i]<l2[j])
		{
			arr[k]=l1[i];
			i++;
		}
		else
		{
			arr[k]=l2[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k] = l1[i];
		k++;
		i++;
	}

	while(j<n2)
	{
		arr[k] = l1[j];
		k++;
		j++;
	}
}

void merge_sort(long long int arr[], int l, int r)
{
	if (l<r)
	{
		int m = (l+r)/2;

		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int main() {
#if 0
	int size;
	cout << "enter the size of the array" << endl;
	cin >> size;
	int arr[size];
	cout << "enter the elements" << endl;
	for (int i=0 ; i<size ; i++)
	{
		cin >> arr[i];
	}
	cout << "print the array input" << endl;
	for (int i=0 ; i<size ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//sort
	//insertion_sort(arr, size);
	merge_sort(arr, 0, size-1);

	cout << "print the array sorted" << endl;
	for (int i=0 ; i<size ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cin >> size;
#else

	int i=0;
	int size = 0;
	string line;
	ifstream file;
	file.open("input.txt");
	while(getline(file,line))
		size++;
	file.close();

	file.open("input.txt");
	long long int arr[size];
	while(file >> arr[i])
	{
		//cout << arr[i] << endl;
		i++;
	}

	file.close();
	cout << "i=" << i << "size = " << size << endl;
	merge_sort(arr, 0, size-1);
	for (int i=0 ; i<size ; i++)
	{
		cout << arr[i] << endl;
	}

	cin >> i;
#endif
	return 0;
}
