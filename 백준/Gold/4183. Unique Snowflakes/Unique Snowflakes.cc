#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		unordered_set<ll>ss;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		int left = 0;
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			while (ss.find(v[i]) != ss.end())
			{
				ss.erase(v[left++]);
			}
			ss.insert(v[i]);
			ans = max(ans, (ll)i - (ll)left + 1LL);
		}
		cout << ans << '\n';
	}
	return 0;
}