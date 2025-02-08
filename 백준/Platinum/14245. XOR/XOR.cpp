#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>tree;
vector<ll>lazy;
vector<ll>ary;

ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = ary[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) ^ init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int node, int start, int end)
{
	if (lazy[node])
	{
		tree[node] ^= (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, ll value)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] ^= (end - start + 1)* value;
		if (start != end)
		{
			lazy[node * 2] ^= value;
			lazy[node * 2 + 1] ^= value;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, value);
	update(mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

long long query(int start, int end, int node, int left, int right)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) ^ query(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, test = 0;
	cin >> num;
	ary.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> ary[i];
	}
	tree.resize(num * 4);
	lazy.resize(num * 4);
	init(0, num - 1, 1);
	cin >> test;
	for (int i = 0; i < test; ++i)
	{
		int temp = 0;
		cin >> temp;
		switch (temp)
		{
		case 1:
		{
			int start = 0, end = 0;
			ll value = 0;
			cin >> start >> end >> value;
			update(0, num - 1, 1, start, end, value);
			break;
		}
		case 2:
		{
			int idx = 0;
			cin >> idx;
			cout << query(0, num - 1, 1, idx, idx) << "\n";
			break;
		}
		}
	}
	return 0;
}