#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[30001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, h = 0, result = 0, count = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	h = ary[0];
	for (int i = 1; i < num; i++)
	{
		if (ary[i] > h)
		{
			h = ary[i];
			result = Max(result, count);
			count = 0;
		}
		else
		{
			count++;
		}
	}
	result = Max(result, count);
	printf("%d", result);
}