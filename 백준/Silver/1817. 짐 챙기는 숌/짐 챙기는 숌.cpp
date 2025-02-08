#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, now = 1e9, ans = 0;
	cin >> n >> m;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (now + v[i] > m)
		{
			ans++;
			now = v[i];
		}
		else
		{
			now += v[i];
		}
	}
	cout << ans;
	return 0;
}