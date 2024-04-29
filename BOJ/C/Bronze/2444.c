#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int line = 0;
	
	scanf("%d", &line);
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < line - 1; i++)
	{

		for (int j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (int j = 1; j < 2*line -2 - 2*i ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
}
