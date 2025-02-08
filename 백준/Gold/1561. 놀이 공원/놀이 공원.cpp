#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	if (n <= m)
	{
		cout << n;
		return 0;
	}
	vector<ll>v(m);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<ll>temp = v;
	sort(v.begin(), v.end());
	ll left = 0, right = 1e15, time = 0, hito = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll piv = m;
		for (auto& i : v)
		{
			piv += mid / i;
		}
		if (piv >= n)
		{
			right = mid - 1;
		}
		else
		{
			hito = piv;
			time = mid;
			left = mid + 1;
		}
	}
	for (ll i = time + 1;; ++i) // <- 오버플로우;
	{
		for (int j = 0; j < m; ++j)
		{
			if (i % temp[j] == 0)
			{
				hito++;
			}
			if (hito == n)
			{
				cout << j + 1;
				return 0;
			}
		}
	}
	return 0;
}