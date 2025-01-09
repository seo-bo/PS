#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long ary[1000001] = { 0, };
long long sum[1000001] = { 0, };
long long counts[1001] = { 0, };

long long combi(long long num)
{
	return (((num) * (num - 1)) / 2);
}

int main(void)
{
	long long num = 0, div = 0;
	long long result = 0;
	scanf("%lld %lld", &num, &div);
	getchar();
	for (long long i = 1; i <= num; i++)
	{
		scanf("%lld", &ary[i]);
		sum[i] = (sum[i - 1] + ary[i]) % div;
		counts[sum[i]]++;
	}
	for (long long i = 0; i < div; i++)
	{
		long long get = counts[i];
		if (i == 0)
		{
			result += get;
		}
		result += combi(get);
	}
	printf("%lld", result);
}