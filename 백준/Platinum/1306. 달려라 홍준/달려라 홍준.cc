#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v((n + 10));
	vector<int>tree((n + 10) * 4);
	function<int(int, int, int)> init = [&](int start, int end, int node) -> int
		{
			if (start == end)
			{
				return tree[node] = v[start];
			}
			int mid = (start + end) / 2;
			return tree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
		};
	function<int(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right) -> int
		{
			if (right < start || end < left)
			{
				return -1;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) / 2;
			return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	init(1, n, 1);
	for (int i = m; i <= n - m + 1; ++i)
	{
		cout << query(1, n, 1, i - m + 1, i + m - 1) << " ";
	}
	return 0;
}