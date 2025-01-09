#include <bits/stdc++.h>
#define MAX 100001
typedef long long ll;
using namespace std;
int in[MAX], out[MAX];
vector<int>graph[MAX];
ll tree[MAX * 4] = { 0, };
ll lazy[MAX * 4] = { 0, };
bool visited[MAX];
int idx = -1;

void dfs(int node)
{
	in[node] = ++idx;
	visited[node] = true;
	for (auto& i : graph[node])
	{
		dfs(i);
	}
	out[node] = idx;
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node])
	{
		tree[node] += lazy[node];
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
		tree[node] += value;
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
	for (int i = 1; i <= num; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp != -1)
		{
			graph[temp].push_back(i);
		}
	}
	for (int i = 1; i <= num; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < test; ++i)
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
}