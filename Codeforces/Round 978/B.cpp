#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, x = 0;
		cin >> n >> x;
		vector<ll>v(n);
		ll sum = 0, maxi = LLONG_MIN;
		for (auto& i : v)
		{
			cin >> i;
			sum += i;
			maxi = max(maxi, i);
		}
		cout << max(maxi, (sum + x - 1LL) / x) << '\n';
	}
	return 0;
}
