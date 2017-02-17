//============================================================================
// Name        : InversionCount.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <set>
#include<algorithm>
using namespace std;


long long int mSort(int arr[], int temp[], int left, int right);
long long int merge(int arr[], int temp[], int left, int mid, int right);

/*
 * calls mSort
 */
long long int mergeSort(int arr[], int array_size)
{
    int *temp = new int [array_size];
    return mSort(arr, temp, 0, array_size - 1);
}

/*
 * sorts the input array and returns the number of inversions in the array.
 */
long long int mSort(int arr[], int temp[], int left, int right)
{
    int mid = 0;
    long long int inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = mSort(arr, temp, left, mid);
        inv_count += mSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    //cout << inv_count << endl;
    return inv_count;
}

/*
 * merges two sorted arrays and returns inversion count in the arrays.
 */
long long int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    long long int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int main() {
	int i=0;
	int size = 100000;
	int arr[size];
	long long int inversion_counter = 0;
	ifstream file;

	file.open("input.txt");

	while(file >> arr[i])
	{
		//cout << arr[i] << endl;
		i++;
	}

	file.close();

	inversion_counter = mergeSort(arr, size);

	//for (int i=0 ; i<size ; i++)
	{
		//cout << arr[i] << endl;
	}

	cout << "inversion counter = " << inversion_counter << endl;
	cin >> i;

	return 0;
}
