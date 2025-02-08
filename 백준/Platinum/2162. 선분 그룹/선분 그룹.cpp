#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pair<pll, pll>>v(n + 1);
	vector<int>parent(n + 1, 0);
	vector<int>rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	auto ccw = [&](pll& a, pll& b, pll& c)
		{
			ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
			temp -= a.second * b.first + b.second * c.first + c.second * a.first;
			return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
		};
	function<int(int)> find = [&](int root) -> int
		{
			if (parent[root] != root)
			{
				parent[root] = find(parent[root]);
			}
			return parent[root];
		};
	auto merge = [&](int root1, int root2)
		{
			int r1 = find(root1);
			int r2 = find(root2);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else if (rank[r1] > rank[r2])
				{
					parent[r2] = r1;
				}
				else
				{
					parent[r2] = r1;
					rank[r1]++;
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a.first >> a.second >> b.first >> b.second;
		if (a > b)
		{
			swap(a, b);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = v[i];
		for (int j = i + 1; j <= n; ++j)
		{
			auto [c, d] = v[j];
			int xy = ccw(a, b, c) * ccw(a, b, d);
			int yx = ccw(c, d, a) * ccw(c, d, b);
			bool check = false;
			if (!xy && !yx)
			{	
				if (a <= d && c <= b)
				{
					check = true;
				}
			}
			else if (xy <= 0 && yx <= 0)
			{
				check = true;
			}
			if (check)
			{
				int r1 = find(i), r2 = find(j);
				if (r1 != r2)
				{
					merge(i, j);
				}
			}
		}
	}
	unordered_map<int, int>mm;
	for (int i = 1; i <= n; ++i)
	{
		int r = find(i);
		mm[r]++;
	}
	cout << mm.size() << '\n';
	int ans = INT_MIN;
	for (auto& i : mm)
	{
		ans = max(ans, i.second);
	}
	cout << ans;
	return 0;
}