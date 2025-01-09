#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long search(int size, int len, long long* ary, long long max)
{
	long long start = 1, end = max;
	long long cen = (start + end) / 2;
	while (start <= end)
	{
		long long sum = 0;
		cen = (start + end) / 2;
		for (long long i = 0; i < size; i++)
		{
			if ((ary[i] - cen) > 0)
			{
				sum += (ary[i] - cen);
			}
		}
		if (sum >= len)
		{
			start = cen + 1;
		}
		else
		{
			end = cen - 1;
		}
	}
	return end;
}



int main(void) 
{
	int num = 0, len = 0;
	long long max = 0;
	scanf("%d %d", &num, &len);
	long long* ary = (long long*)malloc(sizeof(long long) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
		if (max < ary[i])
		{
			max = ary[i];
		}
	}
	printf("%lld", search(num, len, ary, max));
	free(ary);
}