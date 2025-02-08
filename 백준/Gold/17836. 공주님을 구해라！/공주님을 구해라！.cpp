#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MIN
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, t = 0;
	cin >> n >> m >> t;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<vector<int>>>visited(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	queue<ti>q;
	q.push(make_tuple(0, 0, 0, (v[0][0] == 2)));
	visited[0][0][v[0][0] == 2] = 0;
	while (!q.empty())
	{
		auto [x, y, T, s] = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
		{
			cout << T;
			return 0;
		}
		if (t == T)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (s)
				{
					if (visited[nx][ny][0] > T + 1 || visited[nx][ny][1] > T + 1)
					{
						visited[nx][ny][0] = visited[nx][ny][1] = T + 1;
						q.push(make_tuple(nx, ny, T + 1, 1));
					}
				}
				else
				{
					if (v[nx][ny] == 2 && visited[nx][ny][0] > T + 1)
					{
						visited[nx][ny][0] = visited[nx][ny][1] = T + 1;
						q.push(make_tuple(nx, ny, T + 1, 1));
					}
					else if (!v[nx][ny] && visited[nx][ny][0] > T + 1)
					{
						visited[nx][ny][0] = T + 1;
						q.push(make_tuple(nx, ny, T + 1, 0));
					}
				}
			}
		}
	}
	cout << "Fail";
	return 0;
}