#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0;
	cin >> a >> b;
	vector<ll>len(21, 0);
	for (ll i = 2; i <= 19; ++i)
	{
		ll temp = 0;
		for (ll j = 1; j <= 9; ++j)
		{
			ll s = 1;
			for (ll k = 0; k < i - 1; ++k)
			{
				s *= j;
			}
			temp += s;
		}
		len[i] = temp;
	}
	auto getter = [&](ll n)
		{
			vector<int>v;
			if (!n)
			{
				v.push_back(0);
				return v;
			}
			while (n > 0)
			{
				v.push_back(n % 10);
				n /= 10;
			}
			reverse(v.begin(), v.end());
			return v;
		};
	vector<vector<vector<ll>>>dp(21, vector<vector<ll>>(3, vector<ll>(12, 0)));
	vector<vector<vector<bool>>>visited(21, vector<vector<bool>>(3, vector<bool>(12, false)));
	function<ll(int, int, bool, vector<int>&)> dfs = [&](int idx, int fst, bool check, vector<int>& vv)
		{
			if (idx == vv.size())
			{
				return 1LL;
			}
			if (visited[idx][check][fst + 1])
			{
				return dp[idx][check][fst + 1];
			}
			ll res = 0;
			ll pivot = check ? 9 : vv[idx];
			if (!idx)
			{
				for (int i = 1; i <= pivot; ++i)
				{
					bool flag = check || (i < pivot);
					res += dfs(idx + 1, i, flag, vv);
				}
			}
			else
			{
				if (fst <= 1)
				{
					if (fst == 1)
					{
						bool flag = check || (0 < pivot);
						res += dfs(idx + 1, fst, flag, vv);
					}
				}
				else
				{
					for (int i = 0; i <= min(pivot, fst - 1LL); ++i)
					{
						bool flag = check || (i < pivot);
						res += dfs(idx + 1, fst, flag, vv);
					}
				}
			}
			visited[idx][check][fst + 1] = true;
			return dp[idx][check][fst + 1] = res;
		};
	auto sv = [&](ll x)
		{
			if (x <= 9)
			{
				return 0LL;
			}
			auto p = getter(x);
			ll ans = 0;
			for (int i = 2; i < p.size(); ++i)
			{
				ans += len[i];
			}
			vector<vector<vector<bool>>>(21, vector<vector<bool>>(3, vector<bool>(12, false))).swap(visited);
			ans += dfs(0, -1, false, p);
			return ans;
		};
	cout << sv(b) - sv(a - 1);
	return 0;
}
