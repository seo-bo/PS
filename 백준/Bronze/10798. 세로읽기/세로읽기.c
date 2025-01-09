#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char ary[5][15];
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", ary[i]);
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ary[j][i] != NULL)
			{
				printf("%c", ary[j][i]);
			}
		}
	}
}