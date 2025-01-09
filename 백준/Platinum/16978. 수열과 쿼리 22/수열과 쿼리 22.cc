#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int, int> ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, cnt = 1, ac = 0;
	cin >> n;
	vector<ll>v((n + 1) * 4), tree((n + 1) * 4);
	function<ll(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				return tree[node] = v[start];
			}
			int mid = (start + end) / 2;
			return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
		};
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int value)
		{
			if (start == end)
			{
				tree[node] = value;
				return;
			}
			int mid = (start + end) / 2;
			if (idx <= mid)
			{
				update(start, mid, node * 2, idx, value);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, idx, value);
			}
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<ll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (left > end || start > right)
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
		cin >> v[i];
	}
	cin >> m;
	vector<ti>q;
	for (int i = 0; i < m; ++i)
	{
		int z = 0, x = 0, y = 0, k = 0;
		cin >> z;
		if (z == 1)
		{
			cin >> x >> y;
			q.push_back(make_tuple(z, x, y, cnt++, -1));
		}
		else
		{
			cin >> k >> x >> y;
			q.push_back(make_tuple(z, x, y, k, ac++));
		}
	}
	vector<ll>ans(ac);
	sort(q.begin(), q.end(), [&](const ti& a, const ti& b)
		{
			if (get<3>(a) == get<3>(b))
			{
				return get<0>(a) < get<0>(b);
			}
			return get<3>(a) < get<3>(b);
		});
	init(1, n, 1);
	for (auto& [a, b, c, d, e] : q)
	{
		if (a == 1)
		{
			update(1, n, 1, b, c);
		}
		else
		{
			ans[e] = query(1, n, 1, b, c);
		}
	}
	for (int i = 0; i < ac; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}