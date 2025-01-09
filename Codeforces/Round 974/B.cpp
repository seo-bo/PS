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
		ll n = 0, k = 0;
		cin >> n >> k;
		ll a = max(n - k + 1, 1LL);
		ll pivot = ((n + 1) / 2) - (a / 2);
		if (pivot % 2)
		{
			cout << no << '\n';
		}
		else
		{
			cout << yes << '\n';
		}
	}
	return 0;
}
