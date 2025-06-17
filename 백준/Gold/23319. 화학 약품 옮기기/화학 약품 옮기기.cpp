#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(2 * n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(n + b);
		graph[n + b].push_back(a);
	}
	vector<bool>visited(2 * n + 1, false);
	vector<pii>v;
	for (int i = 1; i <= 2 * n; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		int pivot = 0, cnt = 0;
		queue<int>q;
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cnt++;
			if (cur <= n) // a에서 b로
			{
				pivot++;
			}
			else // b에서 a로
			{
				pivot--;
			}
			for (auto& k : graph[cur])
			{
				if (!visited[k])
				{
					visited[k] = true;
					q.push(k);
				}
			}
		}
		v.push_back(make_pair(cnt, pivot));
	}
	map<int, map<int, bool>>dp;
	dp[0][0] = true;
	for (auto& [a, b] : v)
	{
		map<int, map<int, bool>>temp = dp;
		for (auto& [c, d] : dp)
		{
			for (auto& [e, f] : d)
			{
				temp[c + a][e + b] = true;
			}
		}
		dp = move(temp);
	}
	for (auto it = dp.rbegin(); it != dp.rend(); ++it)
	{
		if (it->first / 2 <= n / 2 && it->first % 2 == 0)
		{
			if (it->second[0])
			{
				cout << it->first / 2;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}