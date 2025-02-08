#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
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
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1, 0);
	vector<pll>prefix(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = make_pair(prefix[i - 1].first + v[i], i);
	}
	sort(prefix.begin(), prefix.end());
	ll temp = LLONG_MAX;
	ll left = 0, right = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll dif = abs(prefix[i].first - prefix[i - 1].first);
		if (dif < temp)
		{
			temp = dif;
			left = min(prefix[i].second, prefix[i - 1].second);
			right = max(prefix[i].second, prefix[i - 1].second) - 1;
		}
	}
	ll ans = 0;
	left++, right++;
	for (int i = left; i <= right; ++i)
	{
		ans += v[i];
	}
	cout << ans << '\n';
	cout << left<< ' ' << right;
	return 0;
}