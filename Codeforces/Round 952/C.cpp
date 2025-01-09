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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		ll ans = 0, maxi = 0, sum = 0;
		cin >> n;
		vector<ll>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (i == 0 && v[i] == 0)
			{
				ans++;
				continue;
			}
			if (maxi < v[i])
			{
				sum += maxi;
				maxi = v[i];
			}
			else
			{
				sum += v[i];
			}
			if (sum == maxi)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
