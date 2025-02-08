#include <bits/stdc++.h>
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
	int n = 0, m = 0;
	cin >> m >> n;
	vector<vector<vector<int>>>visited(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	bool flag = false;
	deque<ti>dq;
	pii start, end;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'C')
			{
				if (!flag)
				{
					flag = true;
					start = make_pair(i, j);
					for (int k = 0; k < 4; ++k)
					{
						visited[i][j][k] = 0;
					}
				}
				else
				{
					end = make_pair(i, j);
				}
			}
			else
			{
				v[i][j] = str[j];
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = start.first + dir[i][0];
		int ny = start.second + dir[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '*')
		{
			visited[nx][ny][i] = 0;
			dq.push_back(make_tuple(nx, ny, 0, i));
		}
	}
	while (!dq.empty())
	{
		auto [a, b, c, d] = dq.front();
		dq.pop_front();
		if (make_pair(a, b) == end)
		{
			cout << c;
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = a + dir[i][0];
			int ny = b + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '*')
			{
				if (i == d && visited[nx][ny][i] > c)
				{
					visited[nx][ny][i] = c;
					dq.push_front(make_tuple(nx, ny, c, i));
				}
				else if (i != d && visited[nx][ny][i] > c + 1)
				{
					visited[nx][ny][i] = c + 1;
					dq.push_back(make_tuple(nx, ny, c + 1, i));
				}
			}
		}
	}
	return 0;
}