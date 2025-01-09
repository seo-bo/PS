#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
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
			int a = find(root1);
			int b = find(root2);
			if (a != b)
			{
				if (rank[a] > rank[b])
				{
					parent[b] = a;
				}
				else if (rank[a] < rank[b])
				{
					parent[a] = b;
				}
				else
				{
					parent[a] = b;
					rank[b]++;
				}
			}
		};
	deque<ti>dq;
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		dq.push_back(make_tuple(c, a, b));
	}
	sort(dq.begin(), dq.end());
	int e = 0;
	ll ans = 0;
	while (e < n - 2)
	{
		auto [a, b, c] = dq.front();
		dq.pop_front();
		int r1 = find(b), r2 = find(c);
		if (r1 != r2)
		{
			merge(b, c);
			e++;
			ans += a;
		}
	}
	cout << ans;
	return 0;
}