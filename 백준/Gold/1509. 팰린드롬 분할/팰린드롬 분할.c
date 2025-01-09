#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char str[2502];
int dp[2502] = { 0, };
int check[2502][2502] = { 0, };

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	scanf("%s", str + 1);
	int size = strlen(str + 1);
	for (int i = 1; i <= size; i++)
	{
		dp[i] = i;
		check[i][i] = 1;
	}
	for (int i = 1; i < size; i++)
	{
		if (str[i] == str[i + 1])
		{
			check[i][i + 1] = 1;
		}
	}
	for (int i = 2; i <= size; i++)
	{
		for (int j = 1; j <= size - i; j++)
		{
			if (str[j] == str[i + j] && check[j + 1][i + j - 1])
			{
				check[j][i + j] = 1;
			}
		}
	}
	for (int i = 2; i <= size; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (check[j][i])
			{
				dp[i] = Min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	printf("%d",dp[size]);
}