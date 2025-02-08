#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void) // now^2 - pre^2 = g, now^2 - g = pre^2
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll start = sqrt(n);
	vector<ll>ans;
	for (ll i = start;; ++i)
	{
		ll p1 = i * i;
		ll p2 = (i - 1) * (i - 1);
		if (i * i <= n)
		{
			continue;
		}
		if (p1 - p2 > n)
		{
			break;
		}
		ll pivot = p1 - n;
		ll check = sqrt(pivot);
		if (pivot == check * check)
		{
			ans.push_back(i);
		}
	}
	if (ans.empty())
	{
		cout << -1;
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}