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
	int R = 0, C = 0;
	cin >> R >> C;
	vector<vector<char>>v(R, vector<char>(C));
	vector<vector<int>>dir = { {-1,1},{0,1},{1,1} };
	for (int i = 0; i < R; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; ++j)
		{
			v[i][j] = str[j];
		}
	}
	int ans = 0;
	function<bool(int, int)> dfs = [&](int x, int y) -> bool
		{
			if (y == C - 1)
			{
				ans++;
				return true;
			}
			for (int i = 0; i < 3; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && v[nx][ny] == '.')
				{
					v[nx][ny] = 'X';
					if (dfs(nx, ny))
					{
						return true;
					}
				}
			}
			return false;
		};
	for (int i = 0; i < R; ++i)
	{
		if (v[i][0] == 'X')
		{
			continue;
		}
		v[i][0] = 'X';
		dfs(i, 0);
	}
	cout << ans;
	return 0;
}