#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<ll, bool>dp;
	vector<vector<ll>>comb(5, vector<ll>(5, 0));
	auto hash = [&](vector<ll>& v, ll left)
		{
			ll key = 0;
			for (int i = 1; i <= 9; ++i)
			{
				key <<= 4;
				key |= (v[i] & 0xF);
			}
			key <<= 3;
			key |= (left % 0x7);
			return key;
		};
	function<bool(vector<ll>&, ll)> dfs = [&](vector<ll>& v, ll left)
		{
			ll tot = 0;
			for (int i = 1; i <= 9; ++i)
			{
				tot += v[i];
			}
			if (tot != 3 * left)
			{
				return false;
			}
			if (!left)
			{
				return (tot == 0);
			}
			ll key = hash(v, left);
			auto it = dp.find(key);
			if (it != dp.end())
			{
				return it->second;
			}
			bool flag = false;
			int idx = 1;
			while (idx <= 9 && !v[idx])
			{
				idx++;
			}
			if (v[idx] >= 3)
			{
				v[idx] -= 3;
				if (dfs(v, left - 1))
				{
					flag = true;
				}
				v[idx] += 3;
				if (flag)
				{
					return dp[key] = true;
				}
			}
			if (idx <= 7 && v[idx] > 0 && v[idx + 1] > 0 && v[idx + 2] > 0)
			{
				for (int i = 0; i <= 2; ++i)
				{
					v[idx + i]--;
				}
				if (dfs(v, left - 1))
				{
					flag = true;
				}
				for (int i = 0; i <= 2; ++i)
				{
					v[idx + i]++;
				}
			}
			return dp[key] = flag;
		};
	auto seven = [&](vector<ll>& v)
		{
			ll tot = 0, cnt = 0;
			for (int i = 1; i <= 9; ++i)
			{
				tot += v[i];
				if (v[i] == 2)
				{
					cnt++;
				}
				else if (v[i])
				{
					return false;
				}
			}
			if (tot == 14 && cnt == 7)
			{
				return true;
			}
			return false;
		};
	auto normal = [&](vector<ll>& v)
		{
			for (int i = 1; i <= 9; ++i)
			{
				if (v[i] >= 2)
				{
					v[i] -= 2;
					bool flag = dfs(v, 4);
					v[i] += 2;
					if (flag)
					{
						return true;
					}
				}
			}
			return false;
		};
	auto win = [&](vector<ll>& v)
		{
			if (seven(v))
			{
				return true;
			}
			ll tot = 0;
			for (int i = 1; i <= 9; ++i)
			{
				tot += v[i];
			}
			if (tot != 14)
			{
				return false;
			}
			if (normal(v))
			{
				return true;
			}
			return false;
		};
	for (int i = 0; i <= 4; ++i)
	{
		for (int j = 0; j <= 4; ++j)
		{
			if (j > i)
			{
				continue;
			}
			else if (j == 0 || j == i)
			{
				comb[i][j] = 1;
			}
			else
			{
				ll num = 1;
				for (ll k = 0; k < j; ++k)
				{
					num = num * (i - k) / (k + 1);
				}
				comb[i][j] = num;
			}
		}
	}
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	vector<ll>freq(10, 0);
	for (auto& i : v)
	{
		cin >> i;
		freq[i]++;
	}
	ll ans = 0;
	function<void(int, int, vector<ll>&)> btr = [&](int idx, int sum, vector<ll>& vv)
		{
			if (idx == 10)
			{
				if (sum == 14 && win(vv))
				{
					ll res = 1;
					for (int i = 1; i <= 9; ++i)
					{
						res *= comb[freq[i]][vv[i]];
					}
					ans += res;
				}
				return;
			}
			for (int i = 0; i <= freq[idx]; ++i)
			{
				if (sum + i > 14)
				{
					break;
				}
				vv[idx] = i;
				btr(idx + 1, sum + i, vv);
			}
		};
	vector<ll>temp(10, 0);
	btr(1, 0, temp);
	cout << ans;
	return 0;
}