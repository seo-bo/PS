#include <bits/stdc++.h>
#define MAX 500001
typedef long long ll;

using namespace std;
vector<int>in, out;
vector<int>graph[MAX];
vector<ll> tree, lazy, ary, cost;
int idx = 0;

void Resize(int num)
{
	ary.resize(num + 1);
	cost.resize(num + 1);
	in.resize(num + 1);
	out.resize(num + 1);
	tree.resize((num + 1) * 4);
	lazy.resize((num + 1) * 4);
}

void dfs(int node)
{
	in[node] = ++idx;
	for (auto& i : graph[node])
	{
		dfs(i);
	}
	out[node] = idx;
}

ll init(int start, int end, int node)
{
	if (start == end)
	{
		return tree[node] = cost[start + 1];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
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
	int num = 0, test = 0;
	cin >> num >> test;
	Resize(num);
	cin >> ary[1];
	for (int i = 2; i <= num; ++i)
	{
		int temp = 0;
		cin >> ary[i] >> temp;
		graph[temp].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= num; ++i)
	{
		cost[in[i]] = ary[i];
	}
	init(0, num - 1, 1);
	for (int i = 0; i < test; ++i)
	{
		char temp = 0;
		int get = 0;
		cin >> temp >> get;
		switch (temp)
		{
		case 'p':
		{
			ll value = 0;
			cin >> value;
			update(0, num - 1, 1, in[get], out[get] - 1, value);
			break;
		}
		case 'u':
		{
			cout << query(0, num - 1, 1, in[get] - 1, in[get] - 1) << "\n";
			break;
		}
		}
	}
}