#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, suma = 0, sumb = 0;
	cin >> n >> k;
	vector<ll>A, B;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		suma += temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		sumb += temp;
		B.push_back(temp);
	}
	vector<ll>prefixa(k + 1, 0), prefixb(k + 1, 0), suffixa(k + 1, 0), suffixb(k + 1, 0);
	for (int i = 1; i <= min(k, n); ++i)
	{
		prefixa[i] = prefixa[i - 1] + A[i - 1];
		suffixa[i] = suffixa[i - 1] + A[n - i];
		prefixb[i] = prefixb[i - 1] + B[i - 1];
		suffixb[i] = suffixb[i - 1] + B[n - i];
	}
	vector<ll>va(k + 1, 0), vb(k + 1, 0);
	for (int i = 0; i <= k && i <= n; ++i)
	{
		ll rema = LLONG_MIN, remb = LLONG_MIN;
		for (int j = 0; j <= i && j <= n; ++j)
		{
			if ((i - j) > n)
			{
				continue;
			}
			ll cura = 0, curb = 0;
			if (j <= min(k, n) && i - j <= min(k, n))
			{
				cura = prefixa[j] + suffixa[i - j];
				curb = prefixb[j] + suffixb[i - j];
				rema = max(cura, rema);
				remb = max(curb, remb);
			}
		}
		if (rema == LLONG_MIN)
		{
			va[i] = 0;
		}
		else
		{
			va[i] = rema;
		}
		if (remb == LLONG_MIN)
		{
			vb[i] = 0;
		}
		else
		{
			vb[i] = remb;
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i <= k && i <= n; ++i)
	{
		for (int j = 0; j <= min(k - i, n); ++j)
		{
			ans = min(ans, max(suma - va[i], sumb - vb[j]));
		}
	}
	cout << ans;
	return 0;
}