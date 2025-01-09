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
	int n = 0;
	cin >> n;
	ll ans = 0;
	vector<int>path(n - 1, 0);
	vector<int>cost(n, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> path[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
	}
	ll now = cost[0];
	for (int i = 0; i < n - 1; ++i)
	{
		if (now > cost[i])
		{
			now = cost[i];
		}
		ans += now * path[i];
	}
	cout << ans;
	return 0;
}