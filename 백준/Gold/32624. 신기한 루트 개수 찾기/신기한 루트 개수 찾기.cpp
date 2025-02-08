#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int d = 0, f = 0;
		cin >> d >> f;
		graph[d].push_back(f);
		graph[f].push_back(d);
	}
	vector<bool>visited(n + 1, false);
	queue<int>q;
	visited[a] = true;
	for (auto& i : graph[a])
	{
		q.push(i);
		visited[i] = true;
		int cnt = 0;
		bool flag = false;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			if (cur == b)
			{
				flag = true;
				continue;
			}
			cnt++;
			for (auto& i : graph[cur])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}
		if (flag)
		{
			cout << cnt;
			return 0;
		}
	}
	return 0;
}