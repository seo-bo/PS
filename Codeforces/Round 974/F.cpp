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
		ll n = 0, c = 0;
		cin >> n >> c;
		vector<vector<int>>graph(n + 1);
		vector<ll>gold(n + 1, 0);
		vector<vector<ll>>dp(n + 1, vector<ll>(2, 0));
		for (int i = 1; i <= n; ++i)
		{
			cin >> gold[i];
		}
		for (int i = 0; i < n - 1; ++i) 
		{
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		function<void(int, int)> dfs = [&](int p, int node)
			{
				dp[node][0] = 0;
				dp[node][1] = gold[node];
				for (auto& i : graph[node])
				{
					if (i == p) 
					{
						continue;
					}
					dfs(node, i);
					dp[node][0] += max(dp[i][0], dp[i][1]);
					dp[node][1] += max(dp[i][0], dp[i][1] - 2 * c);
				}
			};
		dfs(-1, 1);
		cout << max(dp[1][0], dp[1][1]) << '\n';
	}
	return 0;
}
