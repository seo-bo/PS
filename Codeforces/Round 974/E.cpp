#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0, h = 0;
		cin >> n >> m >> h;
		vector<vector<pii>>graph(n + 1);
		vector<bool>flag(n + 1, false);
		for (int i = 0; i < h; ++i)
		{
			int temp = 0;
			cin >> temp;
			flag[temp] = true;
		}
		for (int i = 0; i < m; ++i)
		{
			ll a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		auto dijkstra = [&](int start)
			{
				vector<vector<ll>>dis(n + 1, vector<ll>(2, LLONG_MAX));
				dis[start][0] = 0;
				priority_queue<tl, vector<tl>, greater<>>pq;
				pq.push(make_tuple(0, start, 0));
				while (!pq.empty())
				{
					auto [t, v, a] = pq.top();
					pq.pop();
					if (dis[v][a] < t)
					{
						continue;
					}
					if (!a && flag[v] && t < dis[v][1])
					{
						dis[v][1] = t;
						pq.push(make_tuple(dis[v][1], v, 1));
					}
					for (auto& [i, j] : graph[v])
					{
						if (!a)
						{
							if (dis[i][0] > t + j)
							{
								dis[i][0] = t + j;
								pq.push(make_tuple(dis[i][0], i, 0));
							}
						}
						else
						{
							if (dis[i][1] > t + (j / 2))
							{
								dis[i][1] = t + (j / 2);
								pq.push(make_tuple(dis[i][1], i, 1));
							}
						}
					}
				}
				vector<ll>pivot(n + 1, LLONG_MAX);
				for (int i = 1; i <= n; ++i)
				{
					pivot[i] = min(dis[i][0], dis[i][1]);
				}
				return pivot;
			};
		vector<ll>mar = dijkstra(1);
		vector<ll>rob = dijkstra(n);
		ll pivot = LLONG_MAX;
		for (int i = 1; i <= n; ++i)
		{
			ll temp = max(mar[i], rob[i]);
			if (temp < pivot)
			{
				pivot = temp;
			}
		}
		cout << (((pivot) == LLONG_MAX) ? -1 : pivot) << '\n';
	}
	return 0;
}
