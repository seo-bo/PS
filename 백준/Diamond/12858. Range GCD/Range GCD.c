#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long long ary[100005], gcdary[100005], tree[100005 * 4], lazy[100005 * 4], gcdtree[100005 * 4];

long long gcd(long long num1, long long num2)
{
	if (!num1)
	{
		return num2;
	}
	else if (!num2)
	{
		return num1;
	}
	long long temp = num1 % num2;
	while (temp)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;
	}
	return num2;
}

long long init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long GCD_init(int start, int end, int node)
{
	if (start == end)
	{
		return gcdtree[node] = gcdary[start];
	}
	int mid = (start + end) / 2;
	return gcdtree[node] = gcd(GCD_init(start, mid, node * 2), GCD_init(mid + 1, end, node * 2 + 1));
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node])
	{
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, long long value)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void GCD_update(int start, int end, int node, int idx, long long value)
{
	if (idx > end || idx < start)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		gcdtree[node] += value;
		return;
	}
	int mid = (start + end) / 2;
	GCD_update(start, mid, node * 2, idx, value);
	GCD_update(mid + 1, end, node * 2 + 1, idx, value);
	gcdtree[node] = gcd(gcdtree[node * 2], gcdtree[node * 2 + 1]);
}


long long query(int start, int end, int node, int idx)
{
	lazy_update(start, end, node);
	if (idx > end || idx < start)
	{
		return 0;
	}
	if (start == end)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, idx) + query(mid + 1, end, node * 2 + 1, idx);
}

long long GCD_query(int start, int end, int node, int left, int right)
{
	if (right < start || end < left)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return gcdtree[node];
	}
	int mid = (start + end) / 2;
	return gcd(GCD_query(start, mid, node * 2, left, right), GCD_query(mid + 1, end, node * 2 + 1, left, right));
}


int main(void)
{
	int num = 0, test = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%lld", &ary[i]);
		if (i == 1)
		{
			continue;
		}
		gcdary[i - 1] = ary[i] - ary[i - 1];
	}
	init(1, num, 1);
	GCD_init(1, num, 1);
	scanf("%d", &test);
	for (int i = 0; i < test; ++i)
	{
		int temp = 0, start = 0, end = 0;
		scanf("%d %d %d", &temp, &start, &end);
		getchar();
		switch (temp)
		{
		case 0:
		{
			printf("%lld\n", gcd(llabs(query(1, num, 1, start)), llabs(GCD_query(1, num, 1, start, end - 1))));
			break;
		}
		default:
		{
			update(1, num, 1, start, end, temp);
			GCD_update(1, num, 1, start - 1, temp);
			GCD_update(1, num, 1, end, -temp);
			break;
		}
		}
	}
	return 0;
}