#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	int pivot = n * m;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<int>visited(n);
	vector<pii>e;
	queue<pii>q;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (!temp)
			{
				e.push_back(make_pair(i, j));
			}
			else
			{
				pivot--;
				if (temp == 2)
				{
					q.push(make_pair(i, j));
				}
				visited[i] |= (1 << j);
			}
		}
	}
	auto bfs = [&]()
		{
			int cnt = pivot;
			queue<pii>qq = q;
			vector<int> vc = visited;
			while (!qq.empty())
			{
				if (cnt <= ans)
				{
					return -1;
				}
				auto [x, y] = qq.front();
				qq.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !(vc[nx] & (1 << ny)))
					{
						vc[nx] |= (1 << ny);
						cnt--;
						qq.push(make_pair(nx, ny));
					}
				}
			}
			return cnt;
		};
	function<void(int, int)> dfs = [&](int depth, int start)
		{
			if (depth == 3)
			{
				ans = max(ans, bfs() - 3);
				return;
			}
			for (int i = start; i < e.size(); ++i)
			{
				auto [x, y] = e[i];
				visited[x] |= (1 << y);
				dfs(depth + 1, i + 1);
				visited[x] &= ~(1 << y);
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}