#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<int, int, int, int>ti;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int k = 0, h = 0, w = 0;
	cin >> k >> w >> h;
	vector<vector<int>>v(h, vector<int>(w, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>>special = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<vector<bool>>> visited(k + 1, vector<vector<bool>>(h, vector<bool>(w, false)));
	queue<ti>dq;
	dq.push(make_tuple(0, 0, 0, 0));
	visited[0][0][0] = true;
	while (!dq.empty())
	{
		auto [a, b, c, d] = dq.front();
		dq.pop();
		if (b == h - 1 && c == w - 1)
		{
			cout << d;
			return 0;
		}
		for (int i = 0; i < 8 && a < k; ++i)
		{
			int nx = b + special[i][0];
			int ny = c + special[i][1];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && !v[nx][ny] && !visited[a + 1][nx][ny])
			{
				visited[a + 1][nx][ny] = true;
				dq.push(make_tuple(a + 1, nx, ny, d + 1));
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = b + dir[i][0];
			int ny = c + dir[i][1];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && !v[nx][ny] && !visited[a][nx][ny])
			{
				visited[a][nx][ny] = true;
				dq.push(make_tuple(a, nx, ny, d + 1));
			}
		}
	}
	cout << -1;
	return 0;
}