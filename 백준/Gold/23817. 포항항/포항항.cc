#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, sx = 0, sy = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	deque<pii>resto;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'K')
			{
				resto.push_back(make_pair(i, j));
			}
			else if (v[i][j] == 'S')
			{
				sx = i, sy = j;
			}
		}
	}
	int len = resto.size();
	if (resto.size() < 5)
	{
		cout << -1;
		return 0;
	}
	resto.push_front(make_pair(sx, sy));
	vector<vector<pii>>graph(len + 1);
	auto bfs = [&](int p)
		{
			vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
			queue<ti>q;
			auto [x, y] = resto[p];
			q.push(make_tuple(x, y, 0));
			dis[x][y] = 0;
			while (!q.empty())
			{
				auto [xx, yy, co] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = xx + dir[i][0];
					int ny = yy + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != 'X' && dis[nx][ny] > co + 1)
					{
						dis[nx][ny] = co + 1;
						q.push(make_tuple(nx, ny, co + 1));
					}
				}
			}
			for (int i = 0; i <= len; ++i)
			{
				if (i == p)
				{
					continue;
				}
				auto [x, y] = resto[i];
				if (dis[x][y] != INT_MAX)
				{
					graph[p].push_back(make_pair(i, dis[x][y]));
				}
			}
		};
	for (int i = 0; i <= len; ++i)
	{
		bfs(i);
	}
	int ans = INT_MAX;
	function<void(int, int, int)> dfs = [&](int now, int mask, int sum)
		{
			if (__builtin_popcount(mask) == 6)
			{
				ans = min(ans, sum);
				return;
			}
			for (auto& i : graph[now])
			{
				if (!(mask & (1 << i.first)))
				{
					dfs(i.first, mask | (1 << i.first), sum + i.second);
				}
			}
		};
	dfs(0, 1, 0);
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}