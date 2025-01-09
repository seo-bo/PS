#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void star(int row, int col, int num)
{
	if ((row / num) % 3 == 1 && (col / num) % 3 == 1)
	{
		printf(" ");
	}
	else if (num / 3 == 0)
	{
		printf("*");
	}
	else
	{
		star(row, col, num / 3);
	}
}


int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			star(i, j, num);
		}
		printf("\n");
	}
}