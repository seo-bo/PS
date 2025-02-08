#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	vector<int>in(n + 1, 0), dp(n + 1, 0);
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		in[b]++;
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& [i, j] : graph[a])
		{
			dp[i] = max(dp[i], dp[a] + j);
			ans = max(ans, dp[i]);
			if (!(--in[i]))
			{
				q.push(i);
			}
		}
	}
	cout << ans;
	return 0;
}