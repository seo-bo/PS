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
	while (1)
	{
		int l = 0, r = 0, c = 0;
		cin >> l >> r >> c;
		if (!l && !r && !c)
		{
			break;
		}
		vector<vector<vector<char>>>grid(l, vector<vector<char>>(r, vector<char>(c)));
		vector<vector<vector<bool>>>visited(l, vector<vector<bool>>(r, vector<bool>(c, false)));
		vector<vector<int>>dir = { {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };
		queue<tuple<int, int, int, int>>q;
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				for (int k = 0; k < c; ++k)
				{
					cin >> grid[i][j][k];
					if (grid[i][j][k] == 'S')
					{
						q.push(make_tuple(i, j, k, 0));
						visited[i][j][k] = true;
					}
				}
			}
		}
		bool check = false;
		auto bfs = [&]
			{
				while (!q.empty())
				{
					auto [a, b, d, e] = q.front();
					q.pop();
					for (int i = 0; i < 6; ++i)
					{
						int na = a + dir[i][0];
						int nb = b + dir[i][1];
						int nd = d + dir[i][2];
						if (na >= 0 && na < l && nb >= 0 && nb < r && nd >= 0 && nd < c && !visited[na][nb][nd])
						{
							if (grid[na][nb][nd] == '.')
							{
								visited[na][nb][nd] = true;
								q.push(make_tuple(na, nb, nd, e + 1));
							}
							else if (grid[na][nb][nd] == 'E')
							{
								cout << "Escaped in " << e + 1 << " minute(s)." << '\n';
								check = true;
								return;
							}
						}
					}
				}
			};
		bfs();
		if (!check)
		{
			cout << "Trapped!" << '\n';
		}
	}
	return 0;
}