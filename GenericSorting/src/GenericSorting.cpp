//============================================================================
// Name        : GenericSorting.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int l1[n1];
	int l2[n2];

	int i,j,k;

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

	while(i<n1 && j<n2)
	{
		if (l1[i]<=l2[j])
		{
			arr[k] = l1[i];
			i++;
		}
		else
		{
			arr[k] = l2[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k] = l1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=l2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l,m,r);
	}
}

int main() {
	int arr[] = {4,3,2,1};
	int size = (sizeof(arr)/sizeof(int));
	int i;

	cout << "size = " << size << endl;
	for(i=0;i<size;i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	mergeSort(arr, 0, (size-1));

	for(i=0;i<size;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
