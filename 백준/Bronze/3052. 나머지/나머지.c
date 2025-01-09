#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 10;
	int count = 42;
	int arr[42];
	
	for (int i = 0; i < 42; i++)
	{
		arr[i] = -1;
	}
	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		scanf("%d", &j);
		arr[j % 42] = j % 42;
	}
	for (int i = 0; i < 42; i++)
	{
		if (arr[i] == -1)
		{
			count--;
		}
	}
	printf("%d", count);
}
