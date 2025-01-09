#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, ans = 0;
	cin >> n;
	vector<pll>s;
	for (ll i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (s.empty())
		{
			s.push_back(make_pair(i, temp));
		}
		else
		{
			while (!s.empty() && s.back().second <= temp)
			{
				ans += i - s.back().first - 1LL;
				s.pop_back();
			}
			s.push_back(make_pair(i, temp));
		}
	}
	while (!s.empty())
	{
		ans += n - s.back().first - 1LL;
		s.pop_back();
	}
	cout << ans;
	return 0;
}