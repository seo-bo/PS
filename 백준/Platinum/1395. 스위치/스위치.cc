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
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int node, int start, int end)
{
	if (lazy[node])
	{
		tree[node] = (end - start + 1) - tree[node]; // 구간이 가진 스위치의 합이니까 빼주기!?
		if (start != end)
		{
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right)
{
	lazy_update(node, start, end);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		tree[node] = (end - start + 1) - tree[node];
		if (start != end)
		{
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right);
	update(mid + 1, end, node * 2 + 1, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
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
		ary[i] = 0;
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
		case 0:
		{
			int start = 0, end = 0;
			cin >> start >> end;
			update(0, num - 1, 1, start - 1, end - 1);
			break;
		}
		case 1:
		{
			int start = 0, end = 0;
			cin >> start >> end;
			cout << query(0, num - 1, 1, start - 1, end - 1) << "\n";
			break;
		}
		}
	}
	return 0;
}