#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long ary[41] = { 0, };
long long left[1LL << 16] = { 0, };
long long right[1LL << 16] = { 0, };
int lsize = 0, rsize = 0;
long long num = 0, knap = 0;
long long result = 0;

void get_left(long long start, long long sum)
{
	if (start == num / 2)
	{
		left[lsize++] = sum;
		return;
	}
	get_left(start + 1, sum + ary[start]);
	get_left(start + 1, sum);
}

void get_right(long long start, long long sum)
{
	if (start == num)
	{
		right[rsize++] = sum;
		return;
	}
	get_right(start + 1, sum + ary[start]);
	get_right(start + 1, sum);
}

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

int upper_search(int size, long long key)
{
	int start = 0, end = size;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (right[cen] <= key)
		{
			start = cen + 1;
		}
		else
		{
			end = cen;
		}
	}
	return start;
}

int main(void)
{
	scanf("%lld %lld", &num, &knap);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	get_left(0, 0);
	get_right(num / 2, 0);
	qsort(left, lsize, sizeof(long long), compare);
	qsort(right, rsize, sizeof(long long), compare);
	for (int i = 0; i < lsize; i++)
	{
		result += upper_search(rsize, knap - left[i]);
	}
	printf("%lld", result);
}
