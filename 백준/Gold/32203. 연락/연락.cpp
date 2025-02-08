#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1, 0), parent(n + 1, 0), rank(n + 1, 0), male(n + 1, 0), female(n + 1, 0), c(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	ll ans = 0;
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
				if (rank[r1] < rank[r2])
				{
					swap(r1, r2);
				}
				parent[r2] = r1;
				if (rank[r1] == rank[r2])
				{
					rank[r1]++;
				}
				ans -= 1LL * male[r1] * female[r1];
				ans -= 1LL * male[r2] * female[r2];
				male[r1] += male[r2];
				female[r1] += female[r2];
				ans += 1LL * male[r1] * female[r1];
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (v[i] % 2)
		{
			male[i] = 1;
		}
		else
		{
			female[i] = 1;
		}
	}
	while (m--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		int r1 = find(a), r2 = find(b);
		if (r1 != r2)
		{
			merge(a, b);
		}
		cout << ans << '\n';
	}
	return 0;
}