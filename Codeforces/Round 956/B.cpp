#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<int>>a(n, vector<int>(m));
		vector<vector<int>>b(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char c;
				cin >> c;
				a[i][j] = c - '0';
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char c;
				cin >> c;
				b[i][j] = c - '0';
			}
		}
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < m - 1; ++j)
			{
				if (a[i][j] != b[i][j]) {
					int diff = (b[i][j] - a[i][j] + 3) % 3;
					if (diff == 1)
					{
						a[i][j] = (a[i][j] + 1) % 3;
						a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
						a[i][j + 1] = (a[i][j + 1] + 2) % 3;
						a[i + 1][j] = (a[i + 1][j] + 2) % 3;
					}
					else if (diff == 2)
					{
						a[i][j] = (a[i][j] + 2) % 3;
						a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3;
						a[i][j + 1] = (a[i][j + 1] + 1) % 3;
						a[i + 1][j] = (a[i + 1][j] + 1) % 3;
					}
				}
			}
		}
		if (a == b)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}
