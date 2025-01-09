#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 딱 봐도 크루스칼같은데 ?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> pivot(3, 0), parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	vector<tl>v(m);
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
	for (int i = 0; i < 3; ++i)
	{
		int temp = 0;
		cin >> temp;
		pivot[temp] = i;
	}
	for (auto& [a, b, c, d] : v)
	{
		cin >> a >> b >> c >> d;
	}
	sort(v.begin(), v.end(), [&](const tl& a, const tl& b)
		{
			if (get<2>(a) != get<2>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return pivot[get<3>(a)] < pivot[get<3>(b)];
		});
	ll ans = 0, e = 0;
	vector<ll>cnt(3, 0), cost(3, 0);
	for (auto& [a, b, c, d] : v)
	{
		if (find(a) != find(b))
		{
			merge(a, b);
			ans += c;
			cnt[d]++;
			cost[d] += c;
			e++;
			if (e == n - 1)
			{
				break;
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < 3; ++i)
	{
		cout << cnt[i] << ' ' << cost[i] << '\n';
	}
	return 0;
}
