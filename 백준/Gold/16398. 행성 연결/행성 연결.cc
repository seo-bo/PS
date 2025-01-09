#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tl;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<tl>v;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
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
					if (rank[r2] == rank[r1])
					{
						rank[r2]++;
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (i == j)
			{
				continue;
			}
			v.push_back(make_tuple(temp, i, j));
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0, e = 0;
	for (int i = 0; i < v.size() && e < n - 1; ++i)
	{
		auto [w, v1, v2] = v[i];
		int r1 = find(v1), r2 = find(v2);
		if (r1 != r2)
		{
			e++;
			ans += w;
			merge(v1, v2);
		}
	}
	cout << ans;
	return 0;
}