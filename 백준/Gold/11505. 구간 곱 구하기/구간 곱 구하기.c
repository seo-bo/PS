#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

long long tree[4 * 1000001] = { 0, };

long long init(long long* ary, long long start, long long end, long long node)
{
	if (start == end)
	{
		return tree[node] = ary[start] % MOD;
	}
	long long mid = (start + end) / 2;
	return tree[node] = init(ary, start, mid, node * 2) * init(ary, mid + 1, end, node * 2 + 1) % MOD;
}

long long mul(long long start, long long end, long long left, long long right, long long node)
{
	if (left > end || right < start)
	{
		return 1;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	long long mid = (start + end) / 2;
	return (mul(start, mid, left, right, node * 2) * mul(mid + 1, end, left, right, node * 2 + 1)) % MOD;
}

void update(long long start, long long end, long long node, long long idx, long long new)
{

	if (idx < start || idx > end)
	{
		return;
	}
	if (start == end)
	{
		tree[node] = new;
		return;
	}
	long long mid = (start + end) / 2;
	update(start, mid, node * 2, idx, new);
	update(mid + 1, end, node * 2 + 1, idx, new);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

int main(void)
{
	long long num = 0, test1 = 0, test2 = 0;
	scanf("%lld %lld %lld", &num, &test1, &test2);
	long long test = test1 + test2;
	long long* ary = (long long*)calloc(num, sizeof(long long));
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
	}
	init(ary, 0, num - 1, 1);
	for (int i = 0; i < test; i++)
	{
		long long temp = 0, temp1 = 0, temp2 = 0;
		scanf("%lld", &temp);
		switch (temp)
		{
		case 1:
		{
			scanf("%lld %lld", &temp1, &temp2);
			update(0, num - 1, 1, temp1 - 1, temp2);
			break;
		}
		case 2:
		{
			scanf("%lld %lld", &temp1, &temp2);
			printf("%lld\n", mul(0, num - 1, temp1 - 1, temp2 - 1, 1));
			break;
		}
		}
	}
}
