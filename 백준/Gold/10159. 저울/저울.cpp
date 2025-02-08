#include <bits/stdc++.h>
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
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; ++i)
	{
		v[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a][b] = 1;
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (v[i][k] != INT_MAX && v[k][j] != INT_MAX && v[i][j] > v[i][k] + v[k][j])
				{
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int ans = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (i != j && v[i][j] == INT_MAX && v[j][i] == INT_MAX)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}