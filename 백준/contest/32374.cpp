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
	int n = 0, k = 0;
	ll pivot_box = 0;
	cin >> n >> k;
	map<ll, int>present;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		present[temp]++;
	}
	map<ll, int>box;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		box[temp]++;
	}
	vector<ll>v(k);
	for (auto& i : v)
	{
		cin >> i;
		if (!(--box[i]))
		{
			box.erase(i);
		}
	}
	auto it = box.end();
	pivot_box = prev(it)->first;
	for (auto& i : v)
	{
		box[i]++;
	}
	for (auto& [i, j] : box)
	{
		if (i < pivot_box)
		{
			for (int a = 0; a < j; ++a)
			{
				auto jt = present.begin();
				if (!(--jt->second))
				{
					present.erase(jt->first);
				}
			}
		}
		else
		{
			ll ans = 0;
			auto jt = present.lower_bound(pivot_box);
			if (jt == present.end() || jt->first > pivot_box)
			{
				ans = prev(jt)->first;
			}
			else
			{
				ans = jt->first;
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
