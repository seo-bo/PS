#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 5 * num; j++)
		{
			printf("@");
		}
		printf("\n");
	}
	for (int i = 0; i < 4*num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("@");
		}
		printf("\n");
	}
}

