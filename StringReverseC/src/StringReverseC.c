/*
 ============================================================================
 Name        : StringReverseC.c
 Author      : Joe
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char* revString(char* string, int size)
{
	char* retString = (char*)malloc(size);
	int count = 0;
	int revCount = 0;
	int i,j = 0;
	for(i = size-1 ; i >= 0 ; i--)
	{
		if(string[i] != ' ')
		{
			count++;
		}
		else
		{
			//printf("count = %d, i = %d\n", count, i);
			int k = i+1;
			for(j = revCount ; count > 0 ; j++)
			{
				retString[j]=string[k++];
				count--;
			}
			retString[j] = ' ';
			revCount = j;
		}
	}
	retString[revCount] = ' ';
	revCount += 1;
	int k = i+1;
	for(j = revCount ; count > 0 ; j++)
	{
		retString[j]=string[k++];
		count--;
	}

	retString[j] = '\n';
	return retString;
}

int main(void)
{
	char string[] = "life is beautiful";
	int size = sizeof(string)/sizeof(char);
	char* revStr;

	printf("size is %d\n", size);

	revStr = revString(string, size);

	for(int i = 0 ; i < size ; i++)
	{
		printf("%c", revStr[i]);
	}

	free(revStr);
	return 0;
}
