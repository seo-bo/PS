#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>parent(n + 1, 0), cost(n + 1, 0), rank(n+1,0);
	iota(parent.begin(), parent.end(), 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	function<int(int)>find = [&](int root)
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
		int a = 0, b = 0;
		cin >> a >> b;
		merge(a, b);
	}
	vector<int>ans(n + 1, INT_MAX);
	for (int i = 1; i <= n; ++i)
	{
		int r = find(i);
		ans[r] = min(ans[r], cost[i]);
	}
	int out = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (parent[i] == i)
		{
			out += ans[i];
		}
	}
	if (out > k)
	{
		cout << "Oh no";
	}
	else
	{
		cout << out;
	}
	return 0;
}