#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < num * 2 - 1 - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < num - 1; i++) // 4
	{
		for (int j = 0; j < num-2-i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 3 + 2*i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}