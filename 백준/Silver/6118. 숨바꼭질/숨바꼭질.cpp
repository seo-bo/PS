#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	vector<pii>dis(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		dis[i].first = i;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int>q;
	visited[1] = true;
	dis[1].second = 0;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = true;
				dis[i].second = dis[cur].second + 1;
				q.push(i);
			}
		}
	}
	sort(dis.begin(), dis.end(), [&](const pii& a, const pii& b)
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second > b.second;
		});
	cout << dis[0].first << ' ' << dis[0].second << ' ';
	int pivot = dis[0].second, cnt = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (pivot != dis[i].second)
		{
			break;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}