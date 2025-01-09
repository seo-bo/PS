#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<bool>>visited(n, vector<bool>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pii>q;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'I')
			{
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + dir[i][0];
			int ny = cur.second + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (!visited[nx][ny] && v[nx][ny] != 'X')
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					if (v[nx][ny] == 'P')
					{
						ans++;
					}
				}
			}
		}
	}
	if (ans)
	{
		cout << ans;
	}
	else
	{
		cout << "TT";
	}
	return 0;
}