#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ary[51];
int main(void)
{
	int i = 0;
	scanf("%s", ary);
	int size = strlen(ary);
	while (1)
	{
		if (i >= size)
		{
			break;
		}
		if (ary[i] == 'X' && ary[i + 1] == 'X' && ary[i + 2] == 'X' && ary[i + 3] == 'X')
		{
			for (int j = i; j < i + 4; j++)
			{
				ary[j] = 'A';
			}
			i += 4;
		}
		else if (ary[i] == 'X' && ary[i + 1] == 'X')
		{
			for (int j = i; j < i + 2; j++)
			{
				ary[j] = 'B';
			}
			i += 2;
		}
		else
			i++;
	}
	for (int i = 0; i < size; i++)
	{
		if (ary[i] == 'X')
		{
			printf("%d", -1);
			return 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%c", ary[i]);
	}
}
