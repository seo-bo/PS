#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll pivot = 1e18;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int q = 0;
	cin >> q;
	vector<ll>v;
	v.push_back(str.size());
	for (ll i = 1; i <= 60; ++i)
	{
		if (v.back() > pivot)
		{
			v.push_back(pivot + 1);
		}
		else
		{
			ll temp = v.back() * 2LL;
			if (temp > pivot)
			{
				temp = pivot + 1;
			}
			v.push_back(temp);
		}
	}
	auto flip = [&](char p)
		{
			if (islower(p))
			{
				return p - 'a' + 'A';
			}
			else
			{
				return p - 'A' + 'a';
			}
		};
	while (q--)
	{
		ll k = 0, flag = 0;
		cin >> k;
		for (ll i = v.size() - 1; i >= 0; --i)
		{
			if (k > v[i])
			{
				k = v[i];
			}
			if (i == 0)
			{
				break;
			}
			ll div = v[i - 1];
			if (k > div)
			{
				k -= div;
				flag ^= 1;
			}
		}
		char ans = str[k - 1];
		if (flag)
		{
			ans = flip(ans);
		}
		cout << ans << ' ';
	}
	return 0;
}
