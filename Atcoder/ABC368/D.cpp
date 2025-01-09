#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>graph(n + 1);
	vector<int> degree(n + 1, 0), r(n + 1, 0), t(k + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> t[i];
		r[t[i]] = 1;
	}
	queue<int>q;
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 1 && !r[i])
		{
			q.push(i);
			visited[i] = true;
		}
	}
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& i : graph[a])
		{
			if (!visited[i])
			{
				degree[i]--;
				if (degree[i] == 1 && !r[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
