#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n), res;
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	int a = 0, b = n - 1;
	while (a < b)
	{
		res.push_back(v[b--]);
		res.push_back(v[a++]);
	}
	if (a == b)
	{
		res.push_back(v[a]);
	}
	ll ans = res[0];
	for (int i = 1; i < n; ++i)
	{
		ans += max(0LL, res[i] - res[i - 1]);
	}
	cout << ans;
	return 0;
}