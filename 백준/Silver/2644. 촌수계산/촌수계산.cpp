#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, a = 0, b = 0, ans = -1;
	cin >> n >> a >> b >> m;
	vector<vector<int>>graph(n+1, vector<int>(n + 1));
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	vector<bool>visited(n + 1, false);
	visited[a] = true;
	queue<pii>q;
	q.push(make_pair(a, 0));
	while (!q.empty())
	{
		pii cur = q.front();
		if (cur.first == b)
		{
			cout << cur.second;
			return 0;
		}
		q.pop();
		for (auto& i : graph[cur.first])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(make_pair(i, cur.second + 1));
			}
		}
	}
	cout << ans;
	return 0;
}