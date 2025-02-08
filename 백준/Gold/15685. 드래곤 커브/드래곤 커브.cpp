#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0;
	cin >> n;
	vector<vector<bool>>grid(110, vector<bool>(110, false));
	vector<vector<int>>dir = { {0,1},{-1,0},{0,-1},{1,0} };
	function<void(int, int, vector<int>&)> dfs = [&](int siz, int pivot, vector<int>& v)
		{
			if (!siz)
			{
				v.push_back(pivot);
				return;
			}
			dfs(siz - 1, pivot, v);
			for (int i = v.size() - 1; i >= 0; --i)
			{
				v.push_back((v[i] + 1) % 4);
			}

		};
	vector<vector<int>>dragon(4);
	for (int i = 0; i < 4; ++i)
	{
		dfs(10, i, dragon[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		int x = 0, y = 0, d = 0, g = 0;
		cin >> y >> x >> d >> g;
		grid[x][y] = true;
		for (int i = 0; i < (1 << g); ++i)
		{
			x = x + dir[dragon[d][i]][0];
			y = y + dir[dragon[d][i]][1];
			if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
			{
				grid[x][y] = true;
			}
		}
	}
	int ans = 0;
	vector<vector<int>>a = { {1,0},{0,1},{1,1} };
	for (int i = 0; i <= 100; ++i)
	{
		for (int j = 0; j <= 100; ++j)
		{
			if (!grid[i][j])
			{
				continue;
			}
			int cnt = 1;
			for (int k = 0; k < 3; ++k)
			{
				int nx = i + a[k][0];
				int ny = j + a[k][1];
				if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100 && grid[nx][ny])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
			if (cnt == 4)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}