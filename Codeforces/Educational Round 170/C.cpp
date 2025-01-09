#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007;
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		map<ll, ll>mm;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			mm[temp]++;
		}
		int len = mm.size();
		auto left = mm.begin();
		ll ans = 0, sum = 0, cnt = 0;
		for (auto i = mm.begin(); i != mm.end(); ++i)
		{
			if (i != mm.begin() && i->first == prev(i)->first + 1)
			{
				sum += i->second;
				cnt++;
			}
			else
			{
				left = i;
				sum = i->second;
				cnt = 1;
			}
			while (cnt > k)
			{
				sum -= left->second;
				left++;
				cnt--;
			}
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}
