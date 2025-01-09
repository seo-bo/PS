#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n, 0);
	vector<ll>fact(21, 1);
	for (ll i = 2; i <= 20; ++i)
	{
		fact[i] = fact[i - 1] * i;
	}
	iota(v.begin(), v.end(), 1);
	ll a = 0;
	cin >> a;
	if (a == 1)
	{
		ll b = 0;
		cin >> b;
		b--;
		vector<int>ans;
		for (int i = n; i >= 1; --i)
		{
			ll pivot = b / fact[i - 1];
			ans.push_back(v[pivot]);
			v.erase(v.begin() + pivot);
			b %= fact[i - 1];
		}
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
	}
	else
	{
		ll ans = 0;
		vector<int>temp(n);
		for (auto& i : temp)
		{
			cin >> i;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < v.size(); ++j)
			{
				if (v[j] == temp[i])
				{
					ans += j * fact[n - i - 1];
					v.erase(v.begin() + j);
					break;
				}
			}
		}
		cout << ans + 1;
	}
	return 0;
}