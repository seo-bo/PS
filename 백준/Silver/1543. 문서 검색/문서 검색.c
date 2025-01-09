#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char docu[2501];
char search[51];

int main(void)
{
	int count = 0;
	gets(docu);
	int dsize = strlen(docu);
	gets(search);
	int ssize = strlen(search);
	for (int i = 0; i < dsize;)
	{
		if (strncmp(docu + i, search, ssize) != 0)
		{
			i++;
		}
		else
		{
			count++;
			i += ssize;
		}
	}
	printf("%d", count);
}