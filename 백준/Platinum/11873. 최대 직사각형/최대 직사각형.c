#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int stack[1001] = { 0, };
int ary[1001][1001] = { 0, };
int left[1001] = { 0, }, right[1001] = { 0, };
int max = 0, head = 0;

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	while (1)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		if (num1 == 0 && num2 == 0)
		{
			break;
		}
		memset(ary, 0, sizeof(ary));
		max = 0;
		for (int i = 0; i < num1; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				int temp = 0;
				scanf("%d", &temp);
				if (temp == 1)
				{
					ary[i][j] = (i == 0 ? 1 : ary[i - 1][j] + 1);
				}
			}
			head = 0;
			for (int j = 0; j < num2; j++)
			{
				while (head > 0 && ary[i][stack[head - 1]] >= ary[i][j])
				{
					right[stack[--head]] = j;
				}
				left[j] = (head == 0 ? 0 : stack[head - 1] + 1);
				stack[head++] = j;
			}
			while (head > 0)
			{
				right[stack[--head]] = num2;
			}
			for (int j = 0; j < num2; j++)
			{
				max = Max(max, ary[i][j] * (right[j] - left[j]));
			}
		}
		printf("%d\n", max);
	}
}