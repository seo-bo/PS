#include <bits/stdc++.h>
#include <unordered_set>
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
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<vector<vector<bool>>>visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
	unordered_map<int, pii>mm = { {0,{2,3}},{2,{0,1}},{1,{2,3}},{3,{0,1}} };
	vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<int>st(3), ed(3);
	for (auto& i : st)
	{
		cin >> i;
		--i;
	}
	for (auto& i : ed)
	{
		cin >> i;
		--i;
	}
	visited[st[0]][st[1]][st[2]] = true;
	queue<ti>q;
	q.push(make_tuple(st[0], st[1], st[2], 0));
	while (!q.empty())
	{
		auto [x, y, d, c] = q.front();
		q.pop();
		if (x == ed[0] && y == ed[1] && d == ed[2])
		{
			cout << c;
			return 0;
		}
		pii dd = mm[d];
		if (!visited[x][y][dd.first])
		{
			visited[x][y][dd.first] = true;
			q.push(make_tuple(x, y, dd.first, c + 1));
		}
		if (!visited[x][y][dd.second])
		{
			visited[x][y][dd.second] = true;
			q.push(make_tuple(x, y, dd.second, c + 1));
		}
		for (int i = 1; i <= 3; ++i)
		{
			int nx = x + dir[d][0] * i;
			int ny = y + dir[d][1] * i;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny])
			{
				if (!visited[nx][ny][d])
				{
					visited[nx][ny][d] = true;
					q.push(make_tuple(nx, ny, d, c + 1));
				}
				continue;
			}
			break;
		}
	}
	return 0;
}