#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		pii home, goal;
		cin >> home.first >> home.second;
		vector<pii>con(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> con[i].first >> con[i].second;
		}
		cin >> goal.first >> goal.second;
		vector<bool>visited(n, false);
		auto bfs = [&](int x, int y)
			{
				queue<pii>q;
				q.push(make_pair(x, y));
				while (!q.empty())
				{
					pii cur = q.front();
					q.pop();
					if (abs(cur.first - goal.first) + abs(cur.second - goal.second) <= 1000)
					{
						return true;
					}
					for (int i = 0; i < n; ++i)
					{
						if (!visited[i])
						{
							if (abs(cur.first - con[i].first) + abs(cur.second - con[i].second) <= 1000)
							{
								visited[i] = true;
								q.push(make_pair(con[i].first, con[i].second));
							}
						}
					}
				}
				return false;
			};
		if (bfs(home.first, home.second))
		{
			cout << "happy" << '\n';
		}
		else
		{
			cout << "sad" << "\n";
		}
	}
	return 0;
}