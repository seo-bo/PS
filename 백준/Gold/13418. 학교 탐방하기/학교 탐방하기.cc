#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef tuple<ll, ll, ll>ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ti>best, worst;
	for (int i = 0; i < m + 1; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		best.push_back(make_tuple(c, a, b));
		worst.push_back(make_tuple(c, a, b));
	}
	sort(best.begin(), best.end());
	sort(worst.begin(), worst.end(), greater<ti>());
	auto cal = [&](vector<ti>& v)
		{
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
					int r1 = find(root1);
					int r2 = find(root2);
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
			ll e = 0, ans = 0;
			for (int i = 0; i <= m && e < n; ++i)
			{
				auto [a, b, c] = v[i];
				ll r1 = find(b), r2 = find(c);
				if (r1 != r2)
				{
					merge(b, c);
					e++;
					if (a == 0)
					{
						ans++;
					}
				}
			}
			return ans;
		};
	ll a = cal(best), b = cal(worst);
	cout << llabs(a * a - b * b);
	return 0;
}