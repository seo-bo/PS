#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, h = 0;
	cin >> n >> m >> h;
	deque<pii>v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 1)
			{
				v.push_front(make_pair(i, j));
			}
			else if (temp == 2)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	int len = v.size();
	vector<vector<pii>>graph(len + 1);
	for (int i = 0; i < len; ++i)
	{
		auto [a, b] = v[i];
		for (int j = i + 1; j < len; ++j)
		{
			auto [c, d] = v[j];
			int dis = abs(a - c) + abs(b - d);
			graph[i].push_back(make_pair(j, dis));
			graph[j].push_back(make_pair(i, dis));
		}
	}
	pii home = v.front();
	v.pop_front();
	int ans = 0;
	function<void(int, int, int, int)> dfs = [&](int node, int mask, int hp, int cnt)
		{
			for (auto& [a, b] : graph[node])
			{
				if (a == 0)
				{
					if (hp >= b)
					{
						ans = max(ans, cnt);
					}
				}
				else if (!(mask & (1 << a)))
				{
					if (hp >= b)
					{
						dfs(a, mask | (1 << a), hp - b + h, cnt + 1);
					}
				}
			}
		};
	dfs(0, 0, m, 0);
	cout << ans;
	return 0;
}