#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)// (n + m + k) / d가 최적??? 무조건 그럴까?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll d = 0, n = 0, m = 0, k = 0, ans = 0;
	bool check = false;
	cin >> d >> n >> m >> k;
	ll pivot = (n + m + k) / d;
	if (n / d + m / d + k / d == pivot)
	{
		check = true;
		ans = max(ans, k);
	}
	if ((n + (d - n % d)) / d + m / d + (k - (d - n % d)) / d == pivot && k >= (d - n % d))
	{
		check = true;
		ans = max(ans, k - (d - n % d));
	}
	if ((m + (d - m % d)) / d + n / d + (k - (d - m % d)) / d == pivot && k >= (d - m % d))
	{
		check = true;
		ans = max(ans, k - (d - m % d));
	}
	if ((n + (d - n % d)) / d + (m + (d - m % d)) / d + (k - (d - n % d) - (d - m % d)) / d == pivot && k >= (d - n % d) + (d - m % d))
	{
		check = true;
		ans = max(ans, k - (d - n % d) - (d - m % d));
	}
	if (!check)
	{
		cout << k;
		return 0;
	}
	cout << ans;
	return 0;
}