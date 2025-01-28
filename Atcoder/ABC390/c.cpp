#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	int a = n, b = -1, c = m, d = -1;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == '#')
			{
				a = min(a, i);
				b = max(b, i);
				c = min(c, j);
				d = max(d, j);
			}
		}
	}
	bool check = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a <= i && i <= b && c <= j && j <= d)
			{
				if (v[i][j] == '.')
				{
					check = false;
					break;
				}
			}
			else
			{
				if (v[i][j] == '#')
				{
					check = false;
					break;
				}
			}
		}
		if (!check)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
