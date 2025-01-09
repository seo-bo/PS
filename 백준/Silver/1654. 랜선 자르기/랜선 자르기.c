#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long search(long long* ary, int size ,long long max, int get)
{
	long long start = 1, end = max;
	{
		while (start <= end)
		{
			long long cen = (start + end) / 2;
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += ary[i] / cen;
			}

			if (sum >= get)
			{
				start = cen + 1;
			}
			else
			{
				end = cen - 1;
			}
		}
	}
	return end;
}



int main(void)
{
	int len = 0, count = 0;
	long long max = 0;
	scanf("%d %d", &len, &count);
	long long * ary = (long long*)malloc(sizeof(long long) * len);
	for (int i = 0; i < len; i++)
	{
		scanf("%lld", &ary[i]);
		if (max < ary[i])
		{
			max = ary[i];
		}
	}
	printf("%lld", search(ary, len, max, count));
	free(ary);
}