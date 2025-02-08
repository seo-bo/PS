#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	vector<vector<int>>dir = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	visited[a][b] = true;
	queue<tuple<int, int, int>>q;
	q.push(make_tuple(a, b, 0));
	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();
		if (get<0>(cur) == c && get<1>(cur) == d)
		{
			cout << get<2>(cur);
			return 0;
		}
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nx = get<0>(cur) + dir[i][0];
			int ny = get<1>(cur) + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (!visited[nx][ny])
				{
					visited[nx][ny] = true;
					q.push(make_tuple(nx, ny, get<2>(cur) + 1));
				}
			}
		}
	}
	cout << -1;
	return 0;
}