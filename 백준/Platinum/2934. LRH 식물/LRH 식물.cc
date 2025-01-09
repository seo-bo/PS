#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[100002 * 4] = { 0, };
ll lazy[100002 * 4] = { 0, };

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

ll update(int start, int end, int node, int left, int right)
{
	lazy_update(start, end, node);
	if (left > end || right < start)
	{
		return tree[node];
	}
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1);
		if (start != end)
		{
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
		return tree[node];
	}
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, left, right) + update(mid + 1, end, node * 2 + 1, left, right);
}

ll query(int start, int end, int node, int idx)
{
	lazy_update(start, end, node);
	if (idx > end || idx < start)
	{
		return 0;
	}
	if (start == end)
	{
		ll temp = tree[node];
		tree[node] = 0;
		return temp;
	}
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, idx) + query(mid + 1, end, node * 2 + 1, idx);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int init = 0, fin = 0;
		cin >> init >> fin;
		cout << query(1, 100000, 1, init) + query(1, 100000, 1, fin) << "\n";
		update(1, 100000, 1, init + 1, fin - 1);
	}
	return 0;
}