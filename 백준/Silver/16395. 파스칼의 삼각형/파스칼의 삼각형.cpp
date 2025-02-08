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
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>v(n + 1, vector<int>(k + 1));
	v[1][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
		}
	}
	cout << v[n][k];
	return 0;
}