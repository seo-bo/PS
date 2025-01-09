#include <bits/stdc++.h>
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
	int r = 0, c = 0;
	cin >> r >> c;
	vector<vector<int>>water(r, vector<int>(c, INT_MAX));
	vector<vector<char>>v(r, vector<char>(c));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pii>q;
	pii s = make_pair(0, 0), e = make_pair(0, 0);
	for (int i = 0; i < r; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; ++j)
		{
			if (str[j] == '*')
			{
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
			else if (str[j] == 'S')
			{
				s = make_pair(i, j);
			}
			else if (str[j] == 'D')
			{
				e = make_pair(i, j);
			}
			v[i][j] = str[j];
		}
	}
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			{
				if (v[nx][ny] == '.' && water[nx][ny] > water[x][y] + 1)
				{
					water[nx][ny] = water[x][y] + 1;
					q.push(make_pair(nx, ny));
				}

			}
		}
	}
	queue<tuple<int, int, int>>qq;
	vector<vector<bool>>visited(r, vector<bool>(c, false));
	auto [a, b] = s;
	visited[a][b] = true;
	qq.push(make_tuple(0, a, b));
	while (!qq.empty())
	{
		auto [_, x, y] = qq.front();
		qq.pop();
		if (make_pair(x, y) == e)
		{
			cout << _;
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c)
			{
				if (!visited[nx][ny] && water[nx][ny] > _ + 1 && v[nx][ny] != 'X')
				{
					visited[nx][ny] = true;
					qq.push(make_tuple(_ + 1, nx, ny));
				}
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}