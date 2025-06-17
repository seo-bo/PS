#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, T = 0;
	cin >> n >> T;
	vector<vector<int>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int temp = 0;
			cin >> temp;
			graph[i].push_back(temp);
		}
	}
	deque<pii>dq;
	dq.push_back(make_pair(0, 1));
	vector<vector<int>>dist(n + 1, vector<int>(21, INT_MAX));
	dist[0][1] = 0;
	while (!dq.empty())
	{
		auto [ver, hei] = dq.front();
		dq.pop_front();
		if (ver == n)
		{
			continue;
		}
		int nxt = ver + 1;
		for (auto& i : graph[nxt])
		{
			if (abs(hei - i) <= 1 || min(20, hei * 2) == i)
			{
				if (dist[nxt][i] > dist[ver][hei])
				{
					dist[nxt][i] = dist[ver][hei];
					dq.push_front(make_pair(nxt, i));
				}
			}
			else
			{
				if (dist[nxt][i] > dist[ver][hei] + 1)
				{
					dist[nxt][i] = dist[ver][hei] + 1;
					dq.push_back(make_pair(nxt, i));
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= 20; ++i)
	{
		if (dist[n][i] <= T)
		{
			ans = min(ans, dist[n][i]);
		}
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}