#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	char arr[11][11];
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = num2 -1; j >= 0; j--)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

