#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int a = 0, b = 0, result = 1;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < a; j++)
		{
			result *= b - j;
			result /= 1 + j;
		}
		printf("%d\n", result);
	}
}