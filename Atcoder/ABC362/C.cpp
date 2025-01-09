#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n);
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	ll lsum = 0, rsum = 0;
	for (auto& i : v)
	{
		lsum += i.first;
		rsum += i.second;
	}
	if (lsum > 0 || rsum < 0)
	{
		cout << "No";
		return 0;
	}
	cout << "Yes" << '\n';
	vector<ll> ans(n);
	for (int i = 0; i < n; ++i)
	{
		ans[i] = v[i].first;
	}
	ll cur = lsum;
	for (int i = 0; i < n; ++i)
	{
		if (!cur)
		{
			break;
		}
		ll left = v[i].first, right = v[i].second;
		if (cur < 0)
		{
			ll dif = min(right - left, -cur);
			ans[i] += dif;
			cur += dif;
		}
		else if (cur > 0)
		{
			ll dif = min(right - left, cur);
			ans[i] -= dif;
			cur -= dif;
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
