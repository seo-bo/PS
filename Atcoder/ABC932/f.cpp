#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n + 1), tree(4 * (n + 1));
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				tree[node] = 1;
				return;
			}
			int mid = (start + end) >> 1;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int delta)
		{
			if (start == end)
			{
				tree[node] = delta;
				return;
			}
			int mid = (start + end) >> 1;
			if (idx <= mid)
			{
				update(start, mid, node * 2, idx, delta);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, idx, delta);
			}
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<int(int, int, int, int)> query = [&](int start, int end, int node, int target)
		{
			if (start == end)
			{
				return start;
			}
			int mid = (start + end) >> 1;
			if (tree[node * 2] >= target)
			{
				return query(start, mid, node * 2, target);
			}
			else
			{
				return query(mid + 1, end, node * 2 + 1, target - tree[node * 2]);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	init(1, n, 1);
	vector<int>ans(n + 1);
	for (int i = n; i >= 1; --i)
	{
		int pivot = query(1, n, 1, v[i]);
		ans[pivot] = i;
		update(1, n, 1, pivot, 0);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
