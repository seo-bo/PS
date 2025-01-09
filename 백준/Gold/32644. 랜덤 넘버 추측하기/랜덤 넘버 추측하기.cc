#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>tree((n + 1) * 4);
	vector<int>cost(n + 1, 0);
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				tree[node] = cost[start];
				return;
			}
			int mid = (start + end) / 2;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int value)
		{
			if (idx < start || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] = value;
				return;
			}
			int mid = (start + end) / 2;
			update(start, mid, node * 2, idx, value);
			update(mid + 1, end, node * 2 + 1, idx, value);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<ll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (right < start || left > end)
			{
				return 0LL;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) / 2;
			return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
		};
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	init(1, n, 1);
	vector<ll>ans;
	for (int i = 0; i < m; ++i)
	{
		ll temp = 0, left = 0;
		cin >> temp;
		if (temp > 1)
		{
			left = query(1, n, 1, 1, temp - 1);
		}
		ll right = query(1, n, 1, 1, temp);
		ll pivot = min(left + 1, right);
		ans.push_back(pivot);
		update(1, n, 1, temp, 0);
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}