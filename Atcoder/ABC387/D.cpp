#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (str[j] == 'S')
			{
				sx = i, sy = j;
			}
			else if (str[j] == 'G')
			{
				ex = i, ey = j;
			}
		}
	}
	vector<vector<vector<bool>>>visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	queue<tp>q;
	q.push(make_tuple(sx, sy, 0, 0));
	q.push(make_tuple(sx, sy, 1, 0));
	visited[sx][sy][0] = visited[sx][sy][1] = true;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!q.empty())
	{
		auto& [a, b, c, d] = q.front();
		q.pop();
		if (a == ex && b == ey)
		{
			cout << d;
			return 0;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = a + dir[c * 2 + i][0];
			int ny = b + dir[c * 2 + i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && !visited[nx][ny][1 - c])
			{
				visited[nx][ny][1 - c] = true;
				q.push(make_tuple(nx, ny, 1 - c, d + 1));
			}
		}
	}
	cout << -1;
	return 0;
}
