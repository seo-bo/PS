#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll s = 0, k = 0, ans = 1, temp = 0;
	cin >> s >> k;
	temp = s;
	while (temp)
	{
		ll pivot = temp / k--;
		temp -= pivot;
		ans *= pivot;
	}
	cout << ans;
	return 0;
}