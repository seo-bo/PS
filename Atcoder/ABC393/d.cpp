#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<ll>v;
	for (ll i = 0; i < n; ++i)
	{
		if (str[i] == '1')
		{
			v.push_back(i);
		}
	}
	ll len = v.size(), target = v[len / 2], ans = 0;
	for (ll i = 0; i < len; ++i)
	{
		ans += llabs(v[i] - (target - len / 2 + i));
	}
	cout << ans;
	return 0;
}
