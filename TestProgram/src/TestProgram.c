/*
 ============================================================================
 Name        : TestProgram.c
 Author      : JKB
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int c, d;
	int a, b;
	int arr[] = {10, 20, 30, 40};
	char e = "a";
	char f = "A";
	int g = (int)e;
	int h = (int)f;
	char *num = (char*)malloc(sizeof(100));
	scanf("%d %d", &c, &d);
	sprintf(num, "%d %d", c, d);
	sscanf(num, "%d%d", &a, &b);
	printf("a = %d, b = %d\n", a, b);
	printf("%d, %d", *(arr), *(arr+2));
	printf("\n%d %d", g, h);
	free(num);
	return EXIT_SUCCESS;
}
