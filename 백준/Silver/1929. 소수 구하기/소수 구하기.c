#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int start = 0, end = 0;
	scanf("%d %d", &start, &end);
	int* ary = malloc(sizeof(int) * (end+1));
	ary[1] = -1;
	for (int i = 2; i <= end; i++)
	{
		for (int j = 2; i * j <= end; j++)
		{
			ary[i * j] = -1;
		}
	}
	for (int i = start; i <= end; i++)
	{
		if (ary[i] != -1)
		{
			printf("%d\n", i);
		}
	}
	free(ary);
}
