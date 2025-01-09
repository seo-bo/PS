#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, k = 0, left = 1, right = INT_MAX, ans = 0;
	cin >> n >> k;
	vector<ll>v(k);
	for (auto& i : v)
	{
		cin >> i;
	}
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll temp = 0;
		for (auto& i : v)
		{
			temp += i / mid;
			if (i % mid) // 안나눠지면 찌꺼기 남음 ㅇㅇ
			{
				temp++;
			}
		}
		if (temp <= n)
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