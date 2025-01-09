#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {1,0}, {0,1} };
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	queue<pii>q;
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	visited[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (v[x][y] == -1)
		{
			cout << "HaruHaru";
			exit(0);
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0] * v[x][y];
			int ny = y + dir[i][1] * v[x][y];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << "Hing";
	return 0;
}