#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<vector<char>> grid(n, vector<char>(n));
		for (int i = 0; i < n; ++i) 
		{
			for (int j = 0; j < n; ++j) 
			{
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < n; i += k) 
		{
			for (int j = 0; j < n; j += k)
			{
				cout << grid[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
