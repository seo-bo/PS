#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num - 1; i++)
	{
		printf(" ");
	}
	printf("*\n");
	for (int i = 1; i <	num; i++)
	{
		for (int j = 0; j < num -1 -i; j++)
		{
			printf(" ");
		}
		printf("*");
		for (int j = 0; j < 2 * i - 1; j++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}
