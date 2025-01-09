#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long answer = 1e9;
long long num1 = 0, num2 = 0;

void dfs(long long num, int temp)
{
	if (num == num2)
	{
		if (answer > temp)
		{
			answer = temp;
			return;
		}
	}
	if (num > num2)
	{
		return;
	}
	dfs(num * 2, temp + 1);
	dfs(num * 10 + 1, temp + 1);
}

int main(void) 
{
	scanf("%lld %lld", &num1, &num2);
	dfs(num1, 1);
	if (answer == 1e9)
	{
		printf("-1");
	}
	else
	{
		printf("%lld", answer);
	}
}