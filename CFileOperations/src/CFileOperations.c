/*
 ============================================================================
 Name        : CFileOperations.c
 Author      : JKB
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;
	char *ch;
	char c;
	char input[] = "My name is Joseph";
	char input2[] = "This is working";

	fp = fopen("file.txt", "w+");
	if ( fp != NULL )
	{
		//fputs(input, fp);
		fwrite(input, sizeof(input), 1, fp);
	}
	else
	{
		printf("#WriteFail");
		return EXIT_FAILURE;
	}
	fclose(fp);

	fp = fopen("file.txt", "r");
	if (fp != NULL)
	{
		fseek(fp, SEEK_SET, 3);
#if 0
		ch = (char*)malloc(sizeof(input));
		fread(ch, sizeof(input), 1, fp);
		printf("%s", ch);
		free(ch);
#else
		while(1)
		{
			c = fgetc(fp);
			if (c == EOF)
				break;
			putc(c, stdout);
		}
#endif
	}
	else
	{
		printf("#ReadFail");
		return EXIT_FAILURE;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}
