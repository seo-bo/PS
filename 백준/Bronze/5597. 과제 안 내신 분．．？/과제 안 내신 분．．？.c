#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 30;
	int arr[30];
	for (int i = 0; i < num1; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < 28; i++)
	{
		int j = 0;
		scanf("%d", &j);
		arr[j-1] = j;
	}
	for (int i = 0; i < num1; i++)
	{
		if (arr[i] == 0)
		{
			printf("%d\n", i + 1);
		}
	}
}
