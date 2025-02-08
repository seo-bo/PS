#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>tree;
vector<ll>lazy;
vector<int>ary;

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
	if (start > right || end < left)
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
	ary.resize(num + 1);
	tree.resize((num + 1) * 4);
	lazy.resize((num + 1) * 4);
	for (int i = 1; i <= num; i++) // 원래하던거처럼 0에서 부터 하지말고 1부터 하는게 편할듯 ㅇㅇ
	{
		cin >> ary[i];
		if (i > 1)
		{
			update(1, num, 1, i, i, ary[i] - ary[i - 1]);
		}
		else
		{
			update(1, num, 1, i, i, ary[i]);
		}
	}
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
			cin >> start >> end;
			update(1, num, 1, start, end, 1);
			update(1, num, 1, end + 1, end + 1, -(end - start + 1));
			break;
		}
		case 2:
		{
			int idx = 0;
			cin >> idx;
			cout << query(1, num, 1, 1, idx) << "\n";
			break;
		}
		}
	}
	return 0;
}