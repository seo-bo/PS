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

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n >> t;
	set<int>s;
	for (int i = 1; i <= t; ++i)
	{
		if (!(t % i))
		{
			s.insert(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		auto it = s.lower_bound(temp);
		if (it == s.end())
		{
			ans += abs(temp - *prev(it));
		}
		else if (it == s.begin())
		{
			ans += abs(temp - *it);
		}
		else
		{
			auto jt = prev(it);
			ans += min(abs(temp - *it), abs(temp - *jt));
		}
	}
	cout << ans;
	return 0;
}