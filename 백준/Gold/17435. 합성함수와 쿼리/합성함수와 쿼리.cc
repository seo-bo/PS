#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n;
	vector<vector<int>>table(19, vector<int>(200001));
	for (int i = 1; i <= n; ++i)
	{
		cin >> table[0][i];
	}
	for (int i = 1; i < 19; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			table[i][j] = table[i - 1][table[i - 1][j]];
		}
	}
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		for (int i = 0; a > 0; ++i)
		{
			if (a & 1)
			{
				b = table[i][b];
			}
			a >>= 1;
		}
		cout << b << '\n';
	}
	return 0;
}