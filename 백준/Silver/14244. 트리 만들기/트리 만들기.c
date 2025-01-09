#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int node = 0, leaf = 0, connect = 0;
	scanf("%d %d", &node, &leaf);
	getchar();
	leaf--;
	while (node - leaf > 1)
	{
		printf("%d %d\n", connect, connect + 1);
		connect++;
		node--;
	}
	int temp = connect + 1;
	for (int i = 0; i < leaf; i++)
	{
		printf("%d %d\n", connect, temp);
		temp++;
	}
}