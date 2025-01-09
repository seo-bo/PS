#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
struct segtype
{
	long long sum;
	long long min;
};

segtype tree[200001 * 4] = { 0, };
segtype lazy[200001 * 4] = { 0, };
long long ary[200001] = { 0, };

segtype init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].sum = ary[start];
		tree[node].min = ary[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	segtype left = init(start, mid, node * 2);
	segtype right = init(mid + 1, end, node * 2 + 1);
	tree[node].sum = left.sum + right.sum;
	tree[node].min = min(left.min, right.min);
	return tree[node];
}

void lazy_update(int node, int start, int end)
{
	if (lazy[node].sum != 0 || lazy[node].min != 0)
	{
		tree[node].sum += (end - start + 1) * lazy[node].sum;
		tree[node].min += lazy[node].min;
		if (start != end)
		{
			lazy[node * 2].sum += lazy[node].sum;
			lazy[node * 2 + 1].sum += lazy[node].sum;
			lazy[node * 2].min += lazy[node].min;
			lazy[node * 2 + 1].min += lazy[node].min;
		}
	}
	lazy[node].sum = 0;
	lazy[node].min = 0;
}

void update(int start, int end, int node, int left, int right, ll diff)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node].sum += (end - start + 1) * diff;
		tree[node].min += diff;
		if (start != end)
		{
			lazy[node * 2].sum += diff;
			lazy[node * 2 + 1].sum += diff;
			lazy[node * 2].min += diff;
			lazy[node * 2 + 1].min += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, diff);
	update(mid + 1, end, node * 2 + 1, left, right, diff);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);
}

long long sum_query(int start, int end, int node, int left, int right)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node].sum;
	}
	int mid = (start + end) / 2;
	return sum_query(start, mid, node * 2, left, right) + sum_query(mid + 1, end, node * 2 + 1, left, right);
}

long long min_query(int start, int end, int node, int left, int right)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return 922337203685477580;
	}
	if (left <= start && end <= right)
	{
		return tree[node].min;
	}
	int mid = (start + end) / 2;
	long long left_value = min_query(start, mid, node * 2, left, right);
	long long right_value = min_query(mid + 1, end, node * 2 + 1, left, right);
	return min(left_value, right_value);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num >> test;
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	init(0, num - 1, 1);
	for (int i = 0; i < test; ++i)
	{
		char temp;
		cin >> temp;
		switch (temp)
		{
		case 'M':
		{
			int start = 0, end = 0;
			cin >> start >> end;
			cout << (min_query(0, num - 1, 1, start - 1, end - 1)) << "\n";
			break;
		}
		case 'P':
		{
			int start = 0, end = 0;
			ll diff = 0;
			cin >> start >> end >> diff;
			update(0, num - 1, 1, start - 1, end - 1, diff);
			break;

		}
		case 'S':
		{
			int start = 0, end = 0;
			cin >> start >> end;
			cout << (sum_query(0, num - 1, 1, start - 1, end - 1)) << "\n";
			break;
		}
		}
	}
	return 0;
}