#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>ary;
vector<pair<ll, ll>>tree; // 최소 , 최대

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = { start, end };
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	tree[node] = { min(tree[node * 2].first,tree[node * 2 + 1].first), max(tree[node * 2].second,tree[node * 2 + 1].second) };
}

void update(int start, int end, int node, ll idx, ll value)
{
	if (idx < start || idx > end)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node] = { value,value };
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
	tree[node] = { min(tree[node * 2].first, tree[node * 2 + 1].first), max(tree[node * 2].second, tree[node * 2 + 1].second) };
}

pair<ll, ll> query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
	{
		return { LLONG_MAX, -1 };
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	pair<ll, ll> lefty = query(start, mid, node * 2, left, right);
	pair<ll, ll> righty = query(mid + 1, end, node * 2 + 1, left, right);
	return { min(lefty.first, righty.first), max(lefty.second, righty.second) };
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int num = 0, get = 0;
		cin >> num >> get;
		ary.resize((num + 1));
		tree.resize((num + 1) * 4, { 0,0 });
		iota(ary.begin(), ary.end(), 0);
		init(0, num - 1, 1);
		for (int i = 0; i < get; ++i)
		{
			int temp = 0, start = 0, end = 0;
			cin >> temp >> start >> end;
			switch (temp)
			{
			case 0:
			{
				update(0, num - 1, 1, start, ary[end]);
				update(0, num - 1, 1, end, ary[start]);
				swap(ary[start], ary[end]);
				break;
			}
			case 1:
			{
				pair<ll, ll> result = query(0, num - 1, 1, min(start, end), max(start, end));
				if (min(start, end) == result.first && max(start, end) == result.second)
				{
					cout << "YES" << "\n";
				}
				else
				{
					cout << "NO" << "\n";
				}
				break;
			}
			}
		}
		vector<ll>().swap(ary);
		vector<pair<ll, ll>>().swap(tree);
	}
	return 0;
}