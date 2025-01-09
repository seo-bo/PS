#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<pii>virus;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
			{
				cnt++;
				virus.push_back(make_pair(i, j));
			}
			else if (v[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	int len = virus.size(), ans = INT_MAX;
	vector<int>per(len, 0);
	fill(per.end() - m, per.end(), 1);
	auto bfs = [&](queue<ti>& q, vector<vector<bool>>& visited)
		{
			int ret = cnt - m, time = 0;
			while (!q.empty())
			{
				auto [x, y, c] = q.front();
				time = max(time, c);
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && v[nx][ny] != 1)
					{
						visited[nx][ny] = true;
						ret--;
						q.push(make_tuple(nx, ny, c + 1));
					}
				}
			}
			return ((ret) ? INT_MAX : time);
		};
	do
	{
		queue<ti>q;
		vector<vector<bool>>visited(n, vector<bool>(n, false));
		for (int i = 0; i < len; ++i)
		{
			if (per[i])
			{
				auto [x, y] = virus[i];
				q.push(make_tuple(x, y, 0));
				visited[x][y] = true;
			}
		}
		ans = min(ans, bfs(q, visited));
	} while (next_permutation(per.begin(), per.end()));
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}