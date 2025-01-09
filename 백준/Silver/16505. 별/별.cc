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
	vector<vector<char>>star(1025, vector<char>(1025, ' '));
	int n = 0;
	cin >> n;
	n = 1 << n;
	// 1일때 2, 2일때 4, 3일때 8.. 2^n이구나
	function<void(int, int, int)> fills = [&](int n, int x, int y)
		{
			if (n == 1)
			{
				star[x][y] = '*';
				return;
			}
			int mid = n / 2;
			fills(mid, x, y);
			fills(mid, x + mid, y);
			fills(mid, x, y + mid);
		};
	fills(n, 0, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			cout << star[i][j];
		}
		(i != n - 1) ? cout << '\n' : cout << "";
	}
	return 0;
}