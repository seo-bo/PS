#include <bits/stdc++.h>
#define MAX 100001
typedef long long ll;
using namespace std;

vector<int> in, out;
vector<int>graph[MAX];
vector<ll> tree, lazy;
int idx = 0;

void dfs(int node)
{
	in[node] = ++idx;
	for (auto& i : graph[node])
	{
		dfs(i);
	}
	out[node] = idx;
}

void Resize(int num)
{
	in.resize(num + 1);
	out.resize(num + 1);
	tree.resize((num + 1) * 4);
	lazy.resize((num + 1) * 4);
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
	int num = 0, test = 0, temp = 0;
	cin >> num >> test;
	Resize(num);
	cin >> temp;
	for (int i = 2; i <= num; i++)
	{
		int temp = 0;
		cin >> temp;
		graph[temp].push_back(i);
	}
	dfs(1);
	for (int i = 0; i < test; i++)
	{
		int temp = 0;
		cin >> temp;
		switch (temp)
		{
		case 1:
		{
			int idx = 0;
			ll value = 0;
			cin >> idx >> value;
			update(0, num - 1, 1, in[idx] - 1, out[idx] - 1, value);
			break;
		}
		case 2:
		{
			int idx = 0;
			cin >> idx;
			cout << query(0, num - 1, 1, in[idx] - 1, in[idx] - 1) << "\n";
			break;
		}
		}
	}
	return 0;
}