#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Hello
{
	int pain;
	int happy;
}Hello;

dp[22][101] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int compare(const void* num1, const void* num2)
{
	return (*(Hello*)num1).pain - (*(Hello*)num2).pain;
}

int main(void)
{
	int num = 0, max_happy = 0;
	scanf("%d", &num);
	Hello* get = (Hello*)malloc(sizeof(Hello) * (num+1));
	for (int i = 0; i <= num; i++)
	{
		if (i == 0)
		{
			get[i].pain = 0;
		}
		else 
		{
			scanf("%d", &get[i].pain);
		}
	}
	for (int i = 0; i <= num; i++)
	{
		if (i == 0)
		{
			get[i].happy = 0;
		}
		else
		{
		scanf("%d", &get[i].happy);
		}
	}
	qsort(get, num, sizeof(Hello), compare);
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (j + get[i].pain < 100)
			{
				dp[i][j] = Max(dp[i - 1][j], get[i].happy + dp[i - 1][j + get[i].pain]);
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i][j]);
			}

			max_happy = Max(max_happy, dp[i][j]);
		}
	}
	printf("%d", max_happy);
	
	free(get);
}