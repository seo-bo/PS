#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = min(n, m); i >= 0; --i)
	{
		for (int j = 0; j < n - i + 1; ++j)
		{
			for (int k = 0; k < m - i + 1; ++k)
			{
				if (v[j][k] == v[j][k + i - 1] && v[j][k + i - 1] == v[j + i - 1][k] && v[j + i - 1][k] == v[j + i - 1][k + i - 1])
				{
					cout << i * i;
					return 0;
				}
			}
		}
	}
	return 0;
}