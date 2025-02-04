#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ld>prefix(n + 1), ans(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		ll pivot = i - v[i] - 1;
		ld ok = prefix[i - 1];
		if (pivot >= 0)
		{
			ok -= prefix[pivot];
		}
		ans[i] = (ld)1.0 + ok / (ld)v[i];
		prefix[i] = prefix[i - 1] + ans[i];
	}
	cout << fixed << setprecision(15) << ans[n];
	return 0;
}