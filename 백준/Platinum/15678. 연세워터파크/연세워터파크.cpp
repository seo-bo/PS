#include <bits/stdc++.h>
#define INF -1e18
typedef long long ll;
typedef long double lb;
using namespace std;

vector<ll>tree;
vector<ll>ary;

void update(int start, int end, int node, int idx, ll value)
{
	if (start > idx || end < idx)
	{
		return;
	}
	if (idx <= start && end <= idx)
	{
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, value);
	update(mid + 1, end, node * 2 + 1, idx, value);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

ll query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
	{
		return INF;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main(void) // 자고 일어나서 단조큐로도 짜보자
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, d = 0;
	ll result = INF;
	cin >> n >> d;
	ary.resize(n + 5);
	tree.resize((n + 5) * 4);
	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		ary[i] = max(ary[i], query(0, n, 1, max(0, i - d), i - 1) + ary[i]);
		result = max(result, ary[i]);
		update(0, n, 1, i, ary[i]);
	}
	cout << result;
	return 0;
}

