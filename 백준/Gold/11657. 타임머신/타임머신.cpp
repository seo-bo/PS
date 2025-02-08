#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	vector<ll>mindis(n + 1, INF);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	mindis[1] = 0;
	auto bellman_ford = [&](int start)
		{
			for (int k = 1; k <= n; ++k)
			{
				for (int a = 1; a <= n; ++a)
				{
					for (auto& j : graph[a])
					{
						auto [b, c] = j;
						if (mindis[a] != INF && mindis[b] > mindis[a] + c)
						{
							mindis[b] = mindis[a] + c;
							if (k == n)
							{
								return false;
							}
						}
					}
				}
			}
			return true;
		};
	if (!bellman_ford(1))
	{
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (mindis[i] == INF)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << mindis[i] << '\n';
		}
	}
	return 0;
}