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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		vector<ll>v;
		bool even = false, odd = false;
		ll num = 0;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			if (temp % 2)
			{
				odd = true;
				num = max(temp, num);
			}
			else
			{
				even = true;
				v.push_back(temp);
			}
		}
		if (!odd || !even)
		{
			cout << 0 << '\n';
			continue;
		}
		sort(v.begin(), v.end());
		ll ans = v.size();
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] < num)
			{
				num = v[i] + num;
			}
			else
			{
				ans++;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
