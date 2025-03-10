#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n + 2, vector<char>(m + 2));
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = str[j - 1];
		}
	}
	vector<vector<int>>dpa(n + 5, vector<int>(m + 5)), dpb(n + 5, vector<int>(m + 5)), l(n + 5, vector<int>(m + 5)), r(n + 5, vector<int>(m + 5));
	vector<ll>a(max(n, m) + 5), b(max(n, m) + 5);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j] == '.')
			{
				continue;
			}
			l[i][j] = (j == 1 ? 1 : l[i][j - 1] + 1);
		}
		for (int j = m; j >= 1; --j)
		{
			if (v[i][j] == '.')
			{
				continue;
			}
			r[i][j] = (j == m ? 1 : r[i][j + 1] + 1);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j] == '.')
			{
				continue;
			}
			if (i == 1)
			{
				dpa[i][j] = 1;
			}
			else
			{
				dpa[i][j] = min(dpa[i - 1][j] + 1, min(l[i][j], r[i][j]));
			}
			a[1]++;
			a[dpa[i][j] + 1]--;
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (v[i][j] == '#')
			{
				continue;
			}
			dpb[i][j] = 1 + min({ dpb[i + 1][j], dpb[i][j + 1],dpb[i + 1][j + 1] });
			b[1]++;
			b[dpb[i][j] + 1]--;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		a[i] += a[i - 1];
		cout << a[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		b[i] += b[i - 1];
		cout << b[i] << ' ';
	}
	return 0;
}