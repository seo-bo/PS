#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll>tp;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>v(n + 1, 0), left(n + 1, 0), s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		while (!s.empty() && v[s.back()] <= v[i])
		{
			s.pop_back();
		}
		if (!s.empty())
		{
			left[i] = s.back();
		}
		s.push_back(i);
	}
	vector<tp>pro(q);
	int cnt = 0;
	for (auto& [a, b, c] : pro)
	{
		cin >> a >> b;
		c = cnt++;
	}
	sort(pro.begin(), pro.end(), [&](const tp& a, const tp& b)
		{
			if (get<0>(a) == get<0>(b))
			{
				return get<1>(a) < get<1>(b);
			}
			return get<0>(a) < get<0>(b);
		});
	vector<pll>build;
	for (int i = 1; i <= n; ++i)
	{
		build.push_back(make_pair(left[i], i));
	}
	sort(build.begin(), build.end(), [&](const pll& a, const pll& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	vector<ll>ans(q, 0), tree((n + 1) * 4, 0);
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int value)
		{
			if (idx > end || idx < start)
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
	function<ll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right) ->ll
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
	ll idx = 0;
	for (auto& [a, b, c] : pro)
	{
		while (idx < build.size() && build[idx].first <= a)
		{
			ll pivot = build[idx++].second;
			update(1, n, 1, pivot, 1);
		}
		ans[c] = idx - query(1, n, 1, 1, b);
	}
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}
