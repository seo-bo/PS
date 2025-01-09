#include <bits/stdc++.h>
#define MAX 100010
typedef long long ll;

using namespace std;
vector<int>in, out;
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

ll init(int start, int end, int node)
{
	lazy[node] = -1; // lazy가 -1이면 업데이트 상태 없음?
	if (start == end)
	{
		return tree[node] = 1; // 처음엔 다 켜져있고
	}
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int start, int end, int node)
{
	if (lazy[node] != -1)
	{
		tree[node] = (end - start + 1) * lazy[node];
		if (start != end)
		{
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

void update(int start, int end, int node, int left, int right, int value)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return;
	}
	if (left <= start && end <= right)
	{
		lazy[node] = value;
		lazy_update(start, end, node);
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
	cin >> num;
	in.resize(num + 1);
	out.resize(num + 1);
	tree.resize((num + 1) * 4);
	lazy.resize((num + 1) * 4);
	for (int i = 1; i <= num; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp != 0)
		{
			graph[temp].push_back(i);
		}
	}
	dfs(1);
	init(0, num - 1, 1);
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int temp = 0, idx = 0;
		cin >> temp >> idx;
		switch (temp)
		{
		case 1:
		{
			update(0, num - 1, 1, in[idx], out[idx] - 1, 1);
			break;
		}
		case 2:
		{
			update(0, num - 1, 1, in[idx], out[idx] - 1, 0);
			break;
		}
		case 3:
		{
			cout << query(0, num - 1, 1, in[idx], out[idx] - 1) << "\n";
			break;
		}
		}
	}
}