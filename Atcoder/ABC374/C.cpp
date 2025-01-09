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
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0;
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	ll ans = sum;
	for (int i = 0; i < (1 << n); ++i)
	{
		ll pa = 0, pb = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				pa += v[j];
			}
			else
			{
				pb += v[j];
			}
		}
		ans = min(ans, max(pa, pb));
	}
	cout << ans;
	return 0;
}
