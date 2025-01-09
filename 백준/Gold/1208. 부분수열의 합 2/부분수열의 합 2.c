#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long ary[41] = { 0, };
long long left[6000001] = { 0, };
long long num = 0, S = 0;
long long result = 0;

void get_left(long long start, long long end, long long sum)
{
	if (start == end)
	{
		left[3000000 + sum]++;
		return;
	}
	get_left(start + 1, end, sum + ary[start]);
	get_left(start + 1, end, sum);
}

void get_right(long long start, long long end, long long sum) 
{
	if (start == end)
	{
		result += left[3000000 + S - sum];
		return;
	}
	get_right(start + 1, end, sum + ary[start]);
	get_right(start + 1, end, sum);
}

int main(void)
{
	scanf("%lld %lld", &num, &S);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	get_left(0, num / 2, 0);
	get_right(num / 2, num, 0);
	if (!S)
	{
		printf("%lld", result - 1);
	}
	else
	{
		printf("%lld", result);
	}
}
