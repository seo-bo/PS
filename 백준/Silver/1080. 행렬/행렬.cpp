#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	vector<vector<int>>b(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			b[i][j] = str[j] - '0';
		}
	}
	if (n < 3 || m < 3)
	{
		if (a != b)
		{
			cout << -1;
			return 0;
		}
	}
	auto rev = [&](int x, int y)
		{
			for (int i = x; i < x + 3; ++i)
			{
				for (int j = y; j < y + 3; ++j)
				{
					a[i][j] ^= 1;
				}
			}
		};
	int ans = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < m - 2; ++j)
		{
			if (a[i][j] != b[i][j])
			{
				ans++;
				rev(i, j);
			}
		}
	}
	if (a != b)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}