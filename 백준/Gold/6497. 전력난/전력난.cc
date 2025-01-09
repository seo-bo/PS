#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		int n = 0, m = 0, e = 0;
		ll ans = 0, total = 0;
		cin >> n >> m;
		if (!n && !m)
		{
			break;
		}
		vector<int>parent(n, 0);
		vector<int>rank(n, 0);
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>>pq;
		iota(parent.begin(), parent.end(), 0);
		function<int(int)> find = [&](int root) ->int
			{
				if (parent[root] != root)
				{
					return parent[root] = find(parent[root]);
				}
				return parent[root];
			};
		auto merge = [&](int root1, int root2)
			{
				int r1 = find(root1), r2 = find(root2);
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
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			total += (ll)c;
			pq.push(make_tuple(-c, a, b));
		}
		while (e < n - 1 && !pq.empty())
		{
			auto [a, b, c] = pq.top();
			pq.pop();
			int r1 = find(b), r2 = find(c);
			if (r1 != r2)
			{
				merge(b, c);
				ans += ll(-a);
				e++;
			}
		}
		cout << abs(total - ans) << '\n';
	}
	return 0;
}