#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, d = 0;
	cin >> h >> w >> d;
	vector<vector<char>>v(h, vector<char>(w));
	vector<vector<bool>>visited(h, vector<bool>(w, false));
	queue<ti>q;
	int ans = 0;
	for (int i = 0; i < h; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'H')
			{
				q.push(make_tuple(i, j, 0));
				visited[i][j] = true;
				ans++;
			}
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!q.empty())
	{
		auto [x, y, dis] = q.front();
		q.pop();
		if (dis >= d)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && v[nx][ny] != '#')
			{
				visited[nx][ny] = true;
				ans++;
				q.push(make_tuple(nx, ny, dis + 1));
			}
		}
	}
	cout << ans;
	return 0;
}
