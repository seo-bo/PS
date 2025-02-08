#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, q = 0;
	cin >> n >> q;
	unordered_map<int, ll>pivot;
	unordered_map<int, ll>dp;
	vector<pii>v(q);
	for (int i = 0; i < q; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a >> b;
		int temp = b;
		while (temp)
		{
			if (pivot.find(temp) == pivot.end())
			{
				ll sum = 0, start = temp, siz = 1, level = 0;
				while (start <= n)
				{
					ll end = min(start + siz - 1, n);
					sum += (start + end) * (end - start + 1) / 2;
					start *= 2, siz *= 2;
				}
				pivot[temp] = sum;
			}
			temp /= 2;
		}
	}
	function<ll(int, int)> dfs = [&](int pre, int root) ->ll
		{
			if (root == 1)
			{
				return dp[1] = pivot[1] - pivot[pre];
			}
			return dp[root] = dfs(root, root / 2) + pivot[root] - pivot[pre];
		};
	for (auto& [i, j] : v)
	{
		if (i == 1)
		{
			unordered_map<int, ll>().swap(dp);
			dfs(0, j);
		}
		else
		{
			if (dp.find(j) != dp.end())
			{
				cout << dp[j] << '\n';
			}
			else
			{
				cout << pivot[j] << '\n';
			}
		}
	}
	return 0;
}