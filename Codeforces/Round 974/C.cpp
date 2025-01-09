#include <bits/stdc++.h>
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
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, sum = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
			sum += i;
		}
		if (n == 1)
		{
			cout << -1 << '\n';
			continue;
		}
		sort(v.begin(), v.end());
		ll pivot = n / 2 + 1;
		if (pivot > n - 1)
		{
			cout << -1 << '\n';
			continue;
		}
		ll mid = v[pivot - 1];
		cout << max(0LL, 2LL * n * mid - sum + 1LL) << '\n';
	}
	return 0;
}
