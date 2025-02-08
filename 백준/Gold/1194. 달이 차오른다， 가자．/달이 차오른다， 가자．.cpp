#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<vector<int>>>visited(n, vector<vector<int>>(m, vector<int>((1 << 7), INT_MAX)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<ti>q;
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = a[j];
			if (v[i][j] == '0')
			{
				q.push(make_tuple(i, j, 0));
				visited[i][j][0] = 0;
			}
		}
	}
	while (!q.empty())
	{
		auto [x, y, c] = q.front();
		q.pop();
		if (v[x][y] == '1')
		{
			cout << visited[x][y][c];
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#')
			{
				int cost = visited[x][y][c], nxt = visited[nx][ny][c];
				if ('a' <= v[nx][ny] && v[nx][ny] <= 'f')
				{
					int pivot = v[nx][ny] - 'a', key = c | (1 << pivot);
					if (visited[nx][ny][key] > cost + 1)
					{
						visited[nx][ny][key] = cost + 1;
						q.push(make_tuple(nx, ny, key));
					}
				}
				else if ('A' <= v[nx][ny] && v[nx][ny] <= 'F')
				{
					int pivot = v[nx][ny] - 'A';
					if ((c & (1 << pivot)) && nxt > cost + 1)
					{
						visited[nx][ny][c] = cost + 1;
						q.push(make_tuple(nx, ny, c));
					}
				}
				else
				{
					if (nxt > cost + 1)
					{
						visited[nx][ny][c] = cost + 1;
						q.push(make_tuple(nx, ny, c));
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}