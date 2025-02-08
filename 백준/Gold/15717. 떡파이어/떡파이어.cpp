#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, ans = 1, b = 2;
	cin >> n;
	if (n <= 1)
	{
		cout << 1;
		return 0;
	}
	n--;
	while (n)
	{
		if (n % 2)
		{
			ans = (ans * b) % MOD;
		}
		b = (b * b) % MOD;
		n /= 2;
	}
	cout << ans;
	return 0;
}