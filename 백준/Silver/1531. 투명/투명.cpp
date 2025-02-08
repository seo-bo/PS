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
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>v(101, vector<int>(101, 0));
	for (int i = 0; i < n; ++i)
	{
		int sx = 0, sy = 0, ex = 0, ey = 0;
		cin >> sx >> sy >> ex >> ey;
		for (int i = sx; i <= ex; ++i)
		{
			for (int j = sy; j <= ey; ++j)
			{
				v[i][j]++;
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (v[i][j] > m)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}