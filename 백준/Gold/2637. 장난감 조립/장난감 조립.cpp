#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll>tl;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	vector<int>in(n + 1, 0), dp(n + 1, 0);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		in[b]++;
		visited[a] = true;
	}
	queue<int>q;
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])
		{
			q.push(i);
			dp[i] = 1;
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& [a, b] : graph[cur])
		{
			dp[a] += dp[cur] * b;
			if (!(--in[a]))
			{
				q.push(a);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			cout << i << ' ' << dp[i] << '\n';
		}
	}
	return 0;
}