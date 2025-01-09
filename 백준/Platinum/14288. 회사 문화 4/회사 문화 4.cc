#include <bits/stdc++.h>
#define MAX 100010
typedef long long ll;

using namespace std;
vector<int>in, out;
vector<int>graph[MAX];

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

void lazy_update(vector<ll>& lazy, vector<ll>& tree, int start, int end, int node)
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

void update(vector<ll>& lazy, vector<ll>& tree, int start, int end, int node, int left, int right, ll value)
{
	lazy_update(lazy, tree, start, end, node);
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
	update(lazy, tree, start, mid, node * 2, left, right, value);
	update(lazy, tree, mid + 1, end, node * 2 + 1, left, right, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>& lazy, vector<ll>& tree, int start, int end, int node, int left, int right)
{
	lazy_update(lazy, tree, start, end, node);
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(lazy, tree, start, mid, node * 2, left, right) + query(lazy, tree, mid + 1, end, node * 2 + 1, left, right);
}

int main(void) // 처음은 down 방향
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> Atree, Alazy, Btree, Blazy;
	int num = 0, test = 0, direction = 0;
	cin >> num >> test;
	in.resize(num + 1);
	out.resize(num + 1);
	Atree.resize((num + 1) * 4);
	Btree.resize((num + 1) * 4);
	Alazy.resize((num + 1) * 4);
	Blazy.resize((num + 1) * 4);
	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp != -1)
		{
			graph[temp].push_back(i);
		}
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
			if (!direction)
			{
				update(Alazy, Atree, 0, num - 1, 1, in[idx] - 1, out[idx] - 1, value);
			}
			else
			{
				update(Blazy, Btree, 0, num - 1, 1, in[idx] - 1, in[idx] - 1, value);
			}
			break;
		}
		case 2:
		{
			int idx = 0;
			cin >> idx;
			cout << query(Blazy, Btree, 0, num - 1, 1, in[idx] - 1, out[idx] - 1) + query(Alazy, Atree, 0, num - 1, 1, in[idx] - 1, in[idx] - 1) << "\n";
			break;
		}
		case 3:
		{
			direction = (direction + 1) % 2;
			break;
		}
		}
	}
}