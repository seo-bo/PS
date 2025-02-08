#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0;
	cin >> n;
	ll ans = INT_MIN;
	vector<ll>v(n + 1, 0), dp1(n + 1, INT_MIN), dp2(n + 1, INT_MIN);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		dp1[i] = max(dp1[i - 1] + v[i], v[i]);
		dp2[i] = max(dp2[i - 1] + v[i], dp1[i - 1]);
		ans = max({ ans,dp1[i],dp2[i] });
	}
	cout << ans;
	return 0;
}