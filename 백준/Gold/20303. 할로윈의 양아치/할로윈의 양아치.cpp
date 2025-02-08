#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>cost(n + 1, 0);
	vector<pll>rank(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		rank[i] = make_pair(1, temp);
	}
	vector<int>parent(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	auto merge = [&](int a, int b)
		{
			int r1 = find(a);
			int r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1].first > rank[r2].first)
				{
					parent[r2] = r1;
					rank[r1].first += rank[r2].first;
					rank[r1].second += rank[r2].second;
					rank[r2] = make_pair(0, 0);
				}
				else
				{
					parent[r1] = r2;
					rank[r2].first += rank[r1].first;
					rank[r2].second += rank[r1].second;
					rank[r1] = make_pair(0, 0);
				}
			}
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
		}
	}
	ll ans = 0;
	unordered_set<int>ss;
	for (int i = 1; i <= n; ++i)
	{
		ss.insert(find(i));
	}
	vector<ll>dp(k, -1);
	dp[0] = 0;
	for (auto& i : ss)
	{
		auto [a, b] = rank[i];
		for (int j = k - 1; j >= a; --j)
		{
			if (dp[j - a] != -1)
			{
				dp[j] = max(dp[j], dp[j - a] + b);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}