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
		int n = 0, m = 0, k = 0;
		cin >> n >> m >> k;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[1][0] = 0;
		vector<vector<tuple<int, int, int>>>graph(n + 1);
		for (int i = 0; i < k; ++i)
		{
			int a = 0, b = 0, c = 0, d = 0;
			cin >> a >> b >> c >> d;
			graph[a].push_back(make_tuple(b, c, d)); // 도착 공항, 비용, 시간
		}
		for (auto& i : graph)
		{
			if (i.empty())
			{
				continue;
			}
			sort(i.begin(), i.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
				{
					if (get<1>(a) == get<1>(b))
					{
						return get<2>(a) < get<2>(b);
					}
					return get<1>(a) < get<1>(b);
				});
		}
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq; // 시간 , 비용, 현재 공항
		pq.push(make_tuple(0, 0, 1));
		while (!pq.empty())
		{
			auto [t, c, cur] = pq.top();
			pq.pop();
			if (dp[cur][c] < t)
			{
				continue;
			}
			for (auto& [i, j, z] : graph[cur])
			{
				if (c + j <= m && dp[i][c + j] > t + z)
				{
					dp[i][c + j] = t + z;
					for (int _ = c + j + 1; _ <= m; ++_)
					{
						if (dp[i][_] > t + z)
						{
							dp[i][_] = t + z;
						}
						else
						{
							break;
						}
					}
					pq.push(make_tuple(t + z, c + j, i));
				}
			}
		}
		int ans = *min_element(dp[n].begin(), dp[n].end());
		if (ans == INT_MAX)
		{
			cout << "Poor KCM" << '\n';
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}