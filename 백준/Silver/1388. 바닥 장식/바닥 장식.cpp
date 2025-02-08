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
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		bool check = false;
		for (int j = 0; j < m; ++j)
		{
			if (!check && v[i][j] == '-')
			{
				check = true;
			}
			else if (check && v[i][j] == '|')
			{
				ans++;
				check = false;
			}
		}
		if (check)
		{
			ans++;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		bool check = false;
		for (int j = 0; j < n; ++j)
		{
			if (!check && v[j][i] == '|')
			{
				check = true;
			}
			else if (check && v[j][i] == '-')
			{
				ans++;
				check = false;
			}
		}
		if (check)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}