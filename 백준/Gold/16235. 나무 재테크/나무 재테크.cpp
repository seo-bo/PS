#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>A(n, vector<int>(n)); // 양분 추가분
	vector<vector<int>>grid(n, vector<int>(n, 5)); // 현재 양분
	vector<vector<deque<int>>>tree(n, vector<deque<int>>(n)); // 어떤 격자의 나무 상태(작은 놈부터 양분을 준다)
	vector<tuple<int, int, int>>inp(m);
	vector<vector<int>>dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (auto& i : A)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		tree[--a][--b].push_back(c);
	}
	auto solve = [&]()
		{
			map<pii, int>mm;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					deque<int>temp;
					int dead = 0;
					auto& a = tree[i][j];
					while (!a.empty())
					{
						if (a.front() > grid[i][j])
						{
							while (!a.empty())
							{
								dead += (a.front() / 2);
								a.pop_front();
							}
						}
						else
						{
							grid[i][j] -= a.front();
							temp.push_back(a.front() + 1);
							if (!(temp.back() % 5))
							{
								mm[make_pair(i, j)]++;
							}
							a.pop_front();
						}
					}
					grid[i][j] += dead;
					tree[i][j] = temp;
				}
			}
			for (auto& [i, j] : mm)
			{
				for (int o = 0; o < 8; ++o)
				{
					int nx = i.first + dir[o][0];
					int ny = i.second + dir[o][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						for (int z = 0; z < j; ++z)
						{
							tree[nx][ny].push_front(1);
						}
					}
				}
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					grid[i][j] += A[i][j];
				}
			}
		};
	for (int i = 0; i < k; ++i)
	{
		solve();
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans += tree[i][j].size();
		}
	}
	cout << ans;
	return 0;
}