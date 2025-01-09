#include <bits/stdc++.h>
#include <unordered_set>
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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, w = 0;
		cin >> n >> m >> w;
		map<pll, ll>mm;
		vector<vector<pll>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			ll pivot = c;
			if (mm.find(make_pair(a, b)) != mm.end())
			{
				pivot = min(mm[make_pair(a, b)], pivot);
			}
			mm[make_pair(a, b)] = pivot;
			mm[make_pair(b, a)] = pivot;
		}
		for (int i = 0; i < w; ++i)
		{
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			ll pivot = -c;
			if (mm.find(make_pair(a, b)) != mm.end())
			{
				pivot = min(mm[make_pair(a, b)], pivot);
			}
			mm[make_pair(a, b)] = pivot;
		}
		for (auto& i : mm)
		{
			auto [a, b] = i.first;
			auto c = i.second;
			graph[a].push_back(make_pair(b, c));
		}
		vector<ll>dis(n + 1, INT_MAX);
		dis[1] = 0;
		bool check = false;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (auto& k : graph[j])
				{
					auto [a, b] = k;
					if (dis[a] > dis[j] + b)
					{
						dis[a] = dis[j] + b;
						if (i == n)
						{
							check = true;
						}
					}
				}
			}
		}
		if (check)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}