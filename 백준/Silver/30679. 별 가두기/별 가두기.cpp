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
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	vector<pii>dir = { {0,1},{1,0},{0,-1},{-1,0} };
	vector<int>ans;
	auto simu = [&](int x, int y) -> bool
		{
			int cnt = 40005, di = 0;
			queue<pii>q;
			q.push(make_pair(x, y));
			while (cnt--)
			{
				pii cur = q.front();
				q.pop();
				int nx = cur.first + dir[di].first * grid[cur.first][cur.second];
				int ny = cur.second + dir[di].second * grid[cur.first][cur.second];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				{
					q.push(make_pair(nx, ny));
				}
				else
				{
					return false;
				}
				di = (di + 1) % 4;
			}
			return true;
		};
	for (int i = 0; i < n; ++i)
	{
		if (simu(i, 0))
		{
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << "\n";
	for (auto& i : ans)
	{
		cout << i << " ";
	}
	return 0;
}