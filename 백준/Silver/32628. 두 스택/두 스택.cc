#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	deque<ll>A, B;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		A.push_front(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		B.push_front(temp);
	}
	vector<ll>prefixa(n + 1, 0), prefixb(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		prefixa[i] = prefixa[i - 1] + A[i - 1];
		prefixb[i] = prefixb[i - 1] + B[i - 1];
	}
	ll left = 0, right = max(prefixa[n], prefixb[n]), ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll a = max(prefixa[n] - mid, 0LL), b = max(prefixb[n] - mid, 0LL);
		ll pa = 0, pb = 0;
		if (a > 0)
		{
			pa = lower_bound(prefixa.begin(), prefixa.end(), a) - prefixa.begin();
			if (pa > n)
			{
				pa = n + 1;
			}
		}
		if (b > 0)
		{
			pb = lower_bound(prefixb.begin(), prefixb.end(), b) - prefixb.begin();
			if (pb > n)
			{
				pb = n + 1;
			}
		}
		if (pa + pb <= k)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}