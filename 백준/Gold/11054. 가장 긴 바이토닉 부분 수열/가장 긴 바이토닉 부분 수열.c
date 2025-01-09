#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[1001] = { 0, };
int dp1[1001] = { 0, };
int dp2[1001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, result = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i <= num; i++)
	{
		dp1[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (ary[j] < ary[i])
			{
				dp1[i] = Max(dp1[i], dp1[j] + 1);
			}
		}
	}
	for (int i = num; i >= 1; i--)
	{
		dp2[i] = 1;
		for (int j = num; j > i; j--)
		{
			if (ary[j] < ary[i])
			{
				dp2[i] = Max(dp2[i], dp2[j] + 1);
			}
		}
	}
	for (int i = 1; i <= num; i++)
	{
		result = Max(result, dp1[i] + dp2[i] - 1);
	}
	printf("%d", result);
}
