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
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0, dif = INT_MAX, ans = 0;
		cin >> n >> k;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		int left = 0, right = n - 1;
		while (left < right)
		{
			ll sum = v[right] + v[left], d = llabs(k - sum);
			if (d < dif)
			{
				dif = d;
				ans = 1;
			}
			else if (d == dif)
			{
				ans++;
			}
			if (sum < k)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}