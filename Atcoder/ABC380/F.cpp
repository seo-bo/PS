#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, l = 0;
	cin >> n >> m >> l;
	int pivot = n + m + l;
	vector<ll>init(pivot, 1);
	for (int i = 1; i < pivot; ++i)
	{
		init[i] = init[i - 1] * 3LL;
	}
	vector<ll>card;
	for (int i = 0; i < pivot; ++i)
	{
		ll temp = 0;
		cin >> temp;
		card.push_back(temp);
	}
	vector<ll>dp(pow(3, pivot) * 2, -1);
	function<bool(ll, ll, ll)> dfs = [&](ll s, ll t, ll c)
		{
			if (s >= pow(3, c))
			{
				return false;
			}
			ll idx = s * 2 + t;
			if (dp[idx] != -1)
			{
				return dp[idx] == 1;
			}
			vector<ll>cur;
			for (int i = 0; i < c; ++i)
			{
				ll p = (s / init[i]) % 3;
				if ((!t && !p) || (t == 1 && p == 1))
				{
					cur.push_back(i);
				}
			}
			if (cur.empty())
			{
				dp[idx] = 0;
				return false;
			}
			for (auto& i : cur)
			{
				ll cost = card[i];
				ll p = (s / init[i]) % 3;
				ll ss = s + (2 - p) * init[i];
				vector<ll>low;
				for (int j = 0; j < c; ++j)
				{
					if (i == j)
					{
						continue;
					}
					ll pp = (ss / init[j]) % 3;
					if (pp == 2 && card[j] < cost)
					{
						low.push_back(j);
					}
				}
				if (!dfs(ss, 1 - t, c))
				{
					dp[idx] = 1;
					return true;
				}
				for (auto& j : low)
				{
					ll o = t;
					ll ss2 = ss + (o - 2) * init[j];
					if (!dfs(ss2, 1 - t, c))
					{
						dp[idx] = 1;
						return true;
					}
				}
			}
			dp[idx] = 0;
			return false;
		};
	ll sett = 0;
	for (int i = 0; i < pivot; ++i)
	{
		if (i >= n)
		{
			sett += init[i];
		}
		if (i >= n + m)
		{
			sett += init[i];
		}
	}
	if (dfs(sett, 0, pivot))
	{
		cout << "Takahashi";
	}
	else
	{
		cout << "Aoki";
	}
	return 0;
}
