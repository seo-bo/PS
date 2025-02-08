#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, w = 0, right = 0;
	cin >> n >> w;
	queue<pii>W;
	vector<vector<int>>grid(n, vector<int>(n, 0));
	vector<vector<int>>water(n, vector<int>(n, 1e8));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1} };
	for (int i = 0; i < w; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		W.push(make_pair(--a, --b));
		water[a][b] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			grid[i][j] = str[j] - '0';
		}
	}
	while (!W.empty())
	{
		auto [x, y] = W.front();
		W.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (water[nx][ny] > water[x][y] + 1)
				{
					water[nx][ny] = water[x][y] + 1;
					W.push(make_pair(nx, ny));
				}
			}
		}
	}
	auto dijkstra = [&]()
		{
			priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
			vector<vector<bool>>visited(n, vector<bool>(n));
			pq.push(make_tuple(0, 0, 0));
			visited[0][0] = true;
			while (!pq.empty())
			{
				auto [a, x, y] = pq.top();
				pq.pop();
				for (int i = 0; i < 8; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (nx == n - 1 && ny == n - 1)
						{
							return a;
						}
						if (grid[nx][ny] && !visited[nx][ny])
						{
							visited[nx][ny] = true;
							pq.push(make_tuple(max(water[nx][ny],a), nx, ny));
						}
					}
				}
			}
			return -1;
		};
	cout << dijkstra();
	return 0;
}