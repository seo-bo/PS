#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_map<ll, ll>dp = { {0,1} };
	ll n = 0, p = 0, q = 0;
	cin >> n >> p >> q;
	function<ll(ll)> dfs = [&](ll node) ->ll
		{
			if (node == 0)
			{
				return 1LL;
			}
			if (dp.find(node) != dp.end())
			{
				return dp[node];
			}
			return dp[node] = dfs(node / p) + dfs(node / q);
		};
	cout << dfs(n);
	return 0;
}