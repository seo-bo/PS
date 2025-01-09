#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

long long tree[4 * 100001] = { 0, };

long long init(long long* ary, long long start, long long end, long long node)
{
	if (start == end)
	{
		tree[node] = ary[start];
		return tree[node];
	}
	long long mid = (start + end) / 2;
	long long left = init(ary, start, mid, node * 2);
	long long right = init(ary, mid + 1, end, node * 2 + 1);
	tree[node] = (left < right) ? left : right;
	return tree[node];
}

long long query(long long start, long long end, long long left, long long right, long long node)
{
	if (left > end || right < start)
	{
		return 9223372036854775807;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	long long mid = (start + end) / 2;
	long long lresult = query(start, mid, left, right, node * 2);
	long long rresult = query(mid + 1, end, left, right, node * 2 + 1);
	return (lresult < rresult) ? lresult : rresult;
}

void update(long long start, long long end, long long node, long long index, long long new) 
{
	if (index < start || index > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = new;
		return;
	}
	long long mid = (start + end) / 2;
	update(start, mid, node * 2, index, new);
	update(mid + 1, end, node * 2 + 1, index, new);
	tree[node] = (tree[node * 2] < tree[node * 2 + 1]) ? tree[node * 2] : tree[node * 2 + 1];
}

int main(void)
{
	long long num = 0, test = 0;
	scanf("%lld", &num);
	long long* ary = (long long*)calloc(num, sizeof(long long));
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	init(ary, 0, num - 1, 1);
	scanf("%lld", &test);
	for (int i = 0; i < test; i++)
	{
		long long temp1 = 0, temp2 = 0, temp3 = 0;
		scanf("%lld %lld %lld", &temp1, &temp2, &temp3);
		switch (temp1)
		{
			case 1:
			{
				update(0, num - 1, 1, temp2 - 1, temp3);
				break;
			}
			case 2:
			{
				printf("%lld\n", query(0, num - 1, temp2 - 1, temp3 - 1, 1));
				break;
			}
		}
	}
}
