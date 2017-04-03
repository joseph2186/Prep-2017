//============================================================================
// Name        : StringReversal.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "malloc.h"

using namespace std;

char* revString(char* string, int size)
{
	char* retString = (char*)malloc(size);
	int count = 0;
	int revCount = 0;
	int j = 0;
	for(int i = size-1 ; i >= 0 ; i--)
	{
		char str = string[i];
		if(str != " ")
		{
			count++;
		}
		else
		{
			int k = i+1;
			for(j = revCount ; count > 0 ; j++)
			{
				retString[j]=string[k++];
				count--;
			}
			retString[j] = " ";
			revCount = j;
		}
	}

	return retString;
}

int main()
{
	char string[] = "life is beautiful";
	int size = sizeof(string)/sizeof(char);
	char* revStr;

	cout << "size in main = " << size << endl;

	revStr = revString(string, size);

	for(int i = 0 ; i < size ; i++)
	{
		cout << revStr[i];
	}

	free(revStr);
	return 0;
}
