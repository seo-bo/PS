#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

dp[101][100001] = { 0, };

typedef struct Knap
{
	int weight;
	int value;
}Knap;

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, crash = 0;
	scanf("%d %d", &num, &crash);
	Knap* get = (Knap*)malloc(sizeof(Knap) * (num + 1));
	for (int i = 1; i <= num; i++)
	{
		scanf("%d %d", &get[i].weight, &get[i].value);
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= crash; j++)
		{
			if (j < get[i].weight)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], get[i].value + dp[i - 1][j - get[i].weight]);
			}
		}
	}

	printf("%d",dp[num][crash]);

	free(get);
}