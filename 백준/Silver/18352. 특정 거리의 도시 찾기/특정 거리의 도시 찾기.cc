#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, k = 0, x = 0;
	cin >> n >> m >> k >> x;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
	}
	visited[x] = true;
	queue<pii>q;
	vector<int>ans;
	q.push(make_pair(x, 0));
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		if (cur.second == k)
		{
			ans.push_back(cur.first);
			continue;
		}
		for (auto& i : graph[cur.first])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(make_pair(i, cur.second + 1));
			}
		}
	}
	if (ans.empty())
	{
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}