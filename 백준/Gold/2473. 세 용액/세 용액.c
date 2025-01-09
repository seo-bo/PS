#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long result[3] = { 0, };

int compare(const void* num1, const void* num2)
{
	if (*(long long*)num1 > *(long long*)num2)
	{
		return 1;
	}
	else if (*(long long*)num1 < *(long long*)num2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	long long* ary = (long long*)malloc(sizeof(long long) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	qsort(ary, num, sizeof(long long), compare);
	long long minsum = 3000000001;
	for (int i = 0; i < num - 2; i++)
	{
		int start = i + 1, end = num - 1;
		while (start < end)
		{
			long long sum = ary[i] + ary[start] + ary[end];
			if (llabs(sum) < minsum)
			{
				minsum = llabs(sum);
				result[0] = ary[i];
				result[1] = ary[start];
				result[2] = ary[end];
			}
			if (sum < 0)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}
	printf("%lld %lld %lld", result[0], result[1], result[2]);
	free(ary);
}