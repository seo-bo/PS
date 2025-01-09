#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll ans = LLONG_MIN;
	vector<vector<ll>>pa(n + 2, vector<ll>(n + 2, 0)), pb(n + 2, vector<ll>(n + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ll temp = 0;
			cin >> temp;
			pa[i][j] = pa[i - 1][j - 1] + temp;
			pb[i][j] = pb[i - 1][j + 1] + temp;
		}
	}
	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= n; ++y)
		{
			for (int s = 0; s + x <= n && y + s <= n; ++s)
			{
				ll a = pa[x + s][y + s] - pa[x - 1][y - 1];
				ll b = pb[x + s][y] - pb[x - 1][y + s + 1];
				ans = max(ans, a - b);
			}
		}
	}
	cout << ans;
	return 0;
}