#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	vector<vector<int>>dir = { {0,1},{1,0} };
	queue<pii>q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (v[x][y] == -1)
		{
			cout << "HaruHaru";
			return 0;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0] * v[x][y];
			int ny = y + dir[i][1] * v[x][y];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << "Hing";
	return 0;
}