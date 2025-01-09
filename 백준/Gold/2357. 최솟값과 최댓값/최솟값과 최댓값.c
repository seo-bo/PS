#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Number
{
	long long min;
	long long max;
}Number;

Number tree[4 * 100001] = { 0, };

Number init(long long* ary, long long start, long long end, long long node)
{
	if (start == end)
	{
		tree[node].min = ary[start];
		tree[node].max = ary[start];
		return tree[node];
	}
	long long mid = (start + end) / 2;
	Number left = init(ary, start, mid, node * 2);
	Number right = init(ary, mid + 1, end, node * 2 + 1);
	tree[node].min = (left.min < right.min) ? left.min : right.min;
	tree[node].max = (left.max > right.max) ? left.max : right.max;
	return tree[node];
}

Number query(long long start, long long end, long long left, long long right, long long node)
{
	if (left > end || right < start)
	{
		Number result = { 9223372036854775807, -9223372036854775807 - 1 };
		return result;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	long long mid = (start + end) / 2;
	Number lresult = query(start, mid, left, right, node * 2);
	Number rresult = query(mid + 1, end, left, right, node * 2 + 1);
	Number result = 
	{
		(lresult.min < rresult.min) ? lresult.min : rresult.min,
		(lresult.max > rresult.max) ? lresult.max : rresult.max
	};
	return result;
}

int main(void)
{
	long long num = 0, test = 0;
	scanf("%lld %lld", &num, &test);
	long long* ary = (long long*)calloc(num, sizeof(long long));
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	init(ary, 0, num - 1, 1);
	for (int i = 0; i < test; i++)
	{
		long long temp1 = 0, temp2 = 0;
		scanf("%lld %lld", &temp1, &temp2);
		Number result = query(0, num - 1, temp1 - 1, temp2 - 1, 1);
		printf("%lld %lld\n", result.min, result.max);
	}
}
