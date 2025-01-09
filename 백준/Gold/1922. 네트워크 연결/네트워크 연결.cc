#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	priority_queue<tuple<ll, int, int>, vector< tuple<ll, int, int>>, greater< tuple<ll, int, int>>>pq;
	vector<int>parent(n + 1, 0);
	vector<int>rank(n + 1, 0);
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
				else if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
				}
				else
				{
					parent[r1] = r2;
					rank[r2]++;
				}
			}
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		ll c = 0;
		cin >> a >> b >> c;
		pq.push(make_tuple(c, a, b));
	}
	int e = 0;
	ll sum = 0;
	while (e < n - 1)
	{
		auto [c, a, b] = pq.top();
		pq.pop();
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
			sum += c;
			e++;
		}
	}
	cout << sum;
	return 0;
}