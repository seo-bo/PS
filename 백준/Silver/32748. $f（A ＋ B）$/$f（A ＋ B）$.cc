#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>v(10, 0);
	vector<ll>rv(10, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < 10; ++i)
	{
		rv[v[i]] = i;
	}
	ll a = 0, b = 0;
	cin >> a >> b;
	auto cal = [&](ll p, vector<ll>& pi)
		{
			string str = to_string(p);
			ll res = 0;
			for (auto& i : str)
			{
				res = res * 10 + pi[i - '0'];
			}
			return res;
		};
	a = cal(a, rv), b = cal(b, rv);
	cout << cal(a + b, v);
	return 0;
}