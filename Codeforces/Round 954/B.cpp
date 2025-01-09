#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>v(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> v[i][j];
			}
		}
		vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
		auto check = [&]()
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < m; ++j)
					{
						bool check = true;
						int ma = 0;
						for (int k = 0; k < 4; ++k)
						{
							int nx = i + dir[k][0];
							int ny = j + dir[k][1];
							if (nx >= 0 && ny >= 0 && nx < n && ny < m)
							{
								if (v[i][j] <= v[nx][ny])
								{
									check = false;
									break;
								}
								else
								{
									ma = max(v[nx][ny], ma);
								}
							}
						}
						if (check)
						{
							v[i][j] = ma;
						}
					}
				}
			};
		check();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << v[i][j] << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}
