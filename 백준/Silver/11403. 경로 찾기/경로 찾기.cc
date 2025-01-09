#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (v[j][i] && v[i][k])
				{
					v[j][k] = 1;
				}
			}
		}
	}
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}