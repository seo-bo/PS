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
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = LLONG_MAX;
	int left = 0, right = 0;
	while (left < n && right < n)
	{
		ll pivot = v[right] - v[left];
		if (pivot >= m)
		{
			ans = min(ans, pivot);
			left++;
		}
		else
		{
			right++;
		}
	}
	cout << ans;
	return 0;
}