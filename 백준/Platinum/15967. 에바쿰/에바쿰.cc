#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>tree, lazy;
vector<ll>ary;
ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2)  + init(mid + 1, end, node * 2 + 1);
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

void update(int start, int end, int node, int left, int right, ll value)
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

ll query(int start, int end, int node, int left, int right)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, loop = 0, hit = 0;
	cin >> num >> loop >> hit;
	ary.resize(num);
	tree.resize(num * 4);
	lazy.resize(num * 4);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	init(0, num - 1, 1);
	for (int i = 0; i < loop + hit; ++i)
	{
		int temp = 0, start = 0, end = 0;
		cin >> temp >> start >> end;
		switch (temp)
		{
		case 1:
		{
			cout << query(0, num - 1, 1, start - 1, end - 1) << "\n";
			break;
		}
		case 2:
		{
			ll value = 0;
			cin >> value;
			update(0, num - 1, 1, start - 1, end - 1, value);
			break;
		}
		}
	}
	return 0;
}