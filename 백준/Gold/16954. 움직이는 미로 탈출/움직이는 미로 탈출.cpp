#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<vector<vector<char>>>v(8, vector<vector<char>>(8, vector<char>(8)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1}, {-1,-1},{-1,1},{1,-1},{1,1},{0,0} };
	for (int i = 0; i < 8; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				if (i + k >= 8)
				{
					break;
				}
				v[k][i + k][j] = str[j];
			}
		}
	}
	if (v[0][0][7] == '#')
	{
		cout << 0;
		return 0;
	}
	vector<vector<vector<bool>>>visited(10, vector<vector<bool>>(8, vector<bool>(8, false)));
	visited[0][7][0] = true;
	queue<ti>q;
	q.push(make_tuple(0, 7, 0));
	while (!q.empty())
	{
		auto [cnt, xx, yy] = q.front();
		q.pop();
		if (cnt == xx)
		{
			cout << 1;
			return 0;
		}
		for (int i = 0; i < 9; ++i)
		{
			int nx = xx + dir[i][0];
			int ny = yy + dir[i][1];
			int cost = cnt + 1;
			if (nx >= cost && nx < 8 && ny >= 0 && ny < 8 && !visited[cost][nx][ny] && v[cnt][nx][ny] != '#' && v[cost][nx][ny] != '#')
			{
				visited[cost][nx][ny] = true;
				q.push(make_tuple(cost, nx, ny));
			}
		}
	}
	cout << 0;
	return 0;
}