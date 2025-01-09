#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long ary[1000001] = { 0, };

void prime()
{
	ary[0] = 1, ary[1] = 1;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
}

int main(void)
{
	prime();
	long long result = 1;
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		long long temp = 0;
		scanf("%lld", &temp);
		if (ary[temp] == 0)
		{
			result *= temp;
			ary[temp] = 1;
		}
	}
	if (result == 1)
	{
		printf("-1");
	}
	else
	{
		printf("%lld", result);
	}
}