#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	queue<pii>q;
	q.push(make_pair(1, 0));
	visited[1] = true;
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		if (cur.second < 2)
		{
			for(auto & i : graph[cur.first])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(make_pair(i, cur.second + 1));
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}