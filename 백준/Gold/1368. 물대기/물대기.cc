#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	rank[0] = 10000;
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			if (parent[root] == root)
			{
				return parent[root];
			}
			return parent[root] = find(parent[root]);
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1), r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r1] = r2;
					if (rank[r1] == rank[r2])
					{
						rank[r2]++;
					}
				}
			}
		};
	ll mini = INT_MAX, ans = 0;
	vector<ti>v;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		mini = min(temp, mini);
		v.push_back(make_tuple(temp, 0, i));
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ll temp = 0;
			cin >> temp;
			if (i == j)
			{
				continue;
			}
			v.push_back(make_tuple(temp, i, j));
		}
	}
	sort(v.begin(), v.end());
	int e = 0;
	bool flag = false;
	int idx = 0;
	for (; idx < v.size() && e < n - 1; ++idx)
	{
		auto [w, v1, v2] = v[idx];
		int r1 = find(v1), r2 = find(v2);
		if (r1 != r2)
		{
			if (v1 == 0 || v2 == 0)
			{
				flag = true;
			}
			e++;
			ans += w;
			merge(v1, v2);
		}
	}
	if (!flag)
	{
		ans += mini;
	}
	else
	{
		for (; idx < v.size(); ++idx)
		{
			auto [w, v1, v2] = v[idx];
			int r1 = find(v1), r2 = find(v2);
			if (r1 != r2)
			{
				e++;
				ans += w;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}