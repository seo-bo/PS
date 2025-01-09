#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long ary[1000003] = { 0, };

void prime()
{
	ary[1] = 1;
	for (int i = 2; i <= 1000003; i++)
	{
		ary[i] = i + 1;
	}
	for (int i = 2; i <= 1000001; i++)
	{
		int divide = i * 2;
		while (divide <= 1000001)
		{
			ary[divide] += i;
			divide += i;
		}
	}
	for (int i = 1; i <= 1000001; i++)
	{
		ary[i] = ary[i - 1] + ary[i];
	}
}

int main(void)
{
	prime();
	int test = 0;
	scanf("%d", &test);
	while (test--)
	{
		int temp = 0;
		scanf("%d", &temp);
		printf("%lld\n", ary[temp]);
	}
}
