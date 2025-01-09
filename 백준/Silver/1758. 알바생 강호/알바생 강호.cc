#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0, ans = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end(), [&](const int& a, const int& b)
		{
			return a > b;
		});
	ll cnt = 1;
	for (auto& i : v)
	{
		ll sum = i - cnt + 1;
		if (sum <= 0)
		{
			break;
		}
		ans += sum;
		cnt++;
	}
	cout << ans;
	return 0;
}