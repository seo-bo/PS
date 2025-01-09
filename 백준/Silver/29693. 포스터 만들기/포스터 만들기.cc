#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, xc = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int left = 0, right = 0;
	if (m % 2)
	{
		left = right = m / 2;
		for (int i = 1; i < n - 1; ++i)
		{
			if (v[i][left - 1] == 'X' && v[i][left] == 'X' && v[i][left + 1] == 'X')
			{	
				v[i][left - 1] = v[i][left + 1] = 'W';
				v[i][left] = 'Y';
				cout << "YES" << '\n';
				for (auto& xx : v)
				{
					for (auto& yy : xx)
					{
						if (yy == 'X')
						{
							cout << 'B';
						}
						else
						{
							cout << yy;
						}
					}
					cout << '\n';
				}
				return 0;
			}
		}
	}
	else
	{
		left = m / 2 - 1, right = m / 2;
		for (int i = 1; i < n - 1; ++i)
		{
			if (v[i][left - 1] == 'X' && v[i][left] == 'X' && v[i][right] == 'X' && v[i][right + 1] == 'X')
			{
				v[i][left - 1] = v[i][right + 1] = 'W';
				v[i][left] = v[i][right] = 'Y';
				cout << "YES" << '\n';
				for (auto& xx : v)
				{
					for (auto& yy : xx)
					{
						if (yy == 'X')
						{
							cout << 'B';
						}
						else
						{
							cout << yy;
						}
					}
					cout << '\n';
				}
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}