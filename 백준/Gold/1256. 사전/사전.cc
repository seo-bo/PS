#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, m = 0;
	ll k = 0;
	cin >> n >> m >> k;
	vector<vector<ll>>dp(n + 1, vector<ll>(m + 1, -1));
	function<ll(int, int)> dfs = [&](int ac, int zc)->ll
		{
			if (ac == 0 || zc == 0)
			{
				return 1LL;
			}
			if (dp[ac][zc] != -1)
			{
				return dp[ac][zc];
			}
			ll pivot = dfs(ac - 1, zc) + dfs(ac, zc - 1);
			return dp[ac][zc] = (pivot > INT_MAX ? INT_MAX : pivot);
		};
	function<string(int, int, ll)> find = [&](int ac, int zc, ll cnt)->string
		{
			if (ac == 0)
			{
				return string(zc, 'z');
			}
			if (zc == 0)
			{
				return string(ac, 'a');
			}
			ll pivot = dfs(ac - 1, zc);
			if (cnt <= pivot)
			{
				return 'a' + find(ac - 1, zc, cnt);
			}
			else
			{
				return 'z' + find(ac, zc - 1, cnt - pivot);
			}
		};
	if (k > dfs(n, m))
	{
		cout << -1;
		return 0;
	}
	cout << find(n, m, k);
	return 0;
}