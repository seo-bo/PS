#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007;
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
	auto check = [&](char a)
		{
			return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
		};
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		vector<ll>v;
		for (int i = 0; i < str.size(); ++i)
		{
			if (check(str[i]))
			{
				v.push_back(i);
			}
		}
		if (v.empty())
		{
			cout << -1 << '\n';
			continue;
		}
		ll ans = 1;
		for (int i = 0; i + 1 < v.size(); ++i)
		{
			ll left = v[i], right = v[i + 1];
			ans = (ans * (right - left)) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}