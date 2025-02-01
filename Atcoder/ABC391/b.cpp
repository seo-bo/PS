#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(n));
	vector<vector<char>>base(m, vector<char>(m));

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			base[i][j] = str[j];
		}
	}
	for (int a = 0; a <= n - m; ++a)
	{
		for (int b = 0; b <= n - m; ++b)
		{
			bool flag = true;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (v[a + i][b + j] != base[i][j])
					{
						flag = false;
						break;
					}
				}
				if (!flag)
				{
					break;
				}
			}
			if (flag)
			{
				cout << a + 1 << ' ' << b + 1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}
