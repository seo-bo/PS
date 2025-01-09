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
	int n = 0, ans = INT_MAX;
	cin >> n;
	vector<vector<int>>cost(n, vector<int>(n, 0));
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : cost)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	function<void(int, int)> dfs = [&](int depth, int value) ->void
		{
			if (depth == 3)
			{
				ans = min(ans, value);
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					int sum = 0;
					if (!visited[i][j])
					{
						bool vcheck = true;
						for (int k = 0; k < 4; ++k)
						{
							int nx = i + dir[k][0];
							int ny = j + dir[k][1];
							if (!(nx >= 0 && nx < n && ny >= 0 && ny < n) || visited[nx][ny])
							{
								vcheck = false;
								break;
							}
						}
						if (vcheck)
						{
							visited[i][j] = true;
							sum += cost[i][j];
							for (int k = 0; k < 4; ++k)
							{
								int nx = i + dir[k][0];
								int ny = j + dir[k][1];
								visited[nx][ny] = true;
								sum += cost[nx][ny];
							}
							dfs(depth + 1, value + sum);
							for (int k = 0; k < 4; ++k)
							{
								int nx = i + dir[k][0];
								int ny = j + dir[k][1];
								visited[nx][ny] = false;
							}
							visited[i][j] = false;
						}
					}
				}
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}