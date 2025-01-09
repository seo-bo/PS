#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int r = 0, c = 0;
	cin >> r >> c;
	ti t;
	pii e;
	vector<vector<char>>v(r, vector<char>(c));
	vector<vector<int>>visited(r, vector<int>(c, INT_MAX));
	vector<vector<int>>dir = { {-1,1},{0,1},{1,1},{-1,-1},{-1,0},{0,-1},{1,0},{1,-1} };
	for (int i = 0; i < r; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < c; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'K')
			{
				t = make_tuple(i, j, 0);
			}
		}
	}
	visited[get<0>(t)][get<1>(t)] = 0;
	deque<ti>dq;
	dq.push_back(t);
	while (!dq.empty())
	{
		auto [x, y, a] = dq.front();
		dq.pop_front();
		if (v[x][y] == '*')
		{
			cout << a;
			return 0;
		}
		for (int i = 0; i < 8; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && v[nx][ny] != '#')
			{
				int cost = a + (i >= 3);
				if (visited[nx][ny] > cost)
				{
					visited[nx][ny] = cost;
					if (i < 3)
					{
						dq.push_front(make_tuple(nx, ny, cost));
					}
					else
					{
						dq.push_back(make_tuple(nx, ny, cost));
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}