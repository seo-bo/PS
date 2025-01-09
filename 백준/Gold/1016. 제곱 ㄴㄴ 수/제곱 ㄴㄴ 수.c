#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ary[1000005] = { 0, };

int main(void)
{
	long long min, max = 0;
	scanf("%lld %lld", &min, &max);
	long long temp = max - min + 1;
	for (long long i = 2; i*i <= max; i++)
	{
		long long sq = i * i;
		long long start = ((min + sq - 1) / sq) * sq;
		for (long long j = start; j <= max; j += sq)
		{
			ary[j - min] = 1;
		}
	}
	long long count = 0;
	for (long long i = 0; i < temp; i++)
	{
		if (ary[i] == 0)
		{
			count++;
		}
	}
	printf("%lld", count);
}