#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) // 그냥 다익스트라 돌리면 안되나?
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>dp(10010, 1e7);
	vector<vector<pii>>graph(10002);
	int n = 0, d = 0;
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, w = 0;
		cin >> a >> b >> w;
		if (b > d)
		{
			continue;
		}
		graph[b].push_back(make_pair(a, w));
	}
	dp[0] = 0;
	for (int i = 1; i <= d; ++i)
	{
		if (graph[i].empty())
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			for (auto& j : graph[i])
			{
				dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[j.first] + j.second));
			}
		}
	}
	cout << dp[d];
	return 0;
}