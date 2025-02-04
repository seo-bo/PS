#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0;
	cin >> n;
	vector<int>v(n + 1, 0), cy1;
	vector<vector<int>>ver(n + 1);
	vector<pii>cy2;
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (i == v[i])
		{
			cy1.push_back(i);
			visited[i] = true;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			int a = i, b = v[a], c = v[b];
			if (a == v[b])
			{
				cy2.push_back(make_pair(a, b));
				visited[a] = visited[b] = true;
			}
			else if (a == v[c])
			{
				ans++;
				visited[a] = visited[b] = visited[c] = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ver[v[i]].push_back(i);
		}
	}
	ll len1 = cy1.size(), len2 = cy2.size();
	ll p1 = (len1 * (len1 - 1LL) * (len1 - 2LL) / 6LL) % MOD;
	ll p2 = (len1 * len2) % MOD;
	ans = (ans + p1 + p2) % MOD;
	for (auto& i : cy1)
	{
		ans = (ans + ((len1 - 1LL) * (ll)ver[i].size()) % MOD) % MOD;
		for (auto& j : ver[i])
		{
			ans = (ans + (ll)ver[j].size()) % MOD;
		}
		ll le = ver[i].size();
		ll pp = (le * (le - 1LL) / 2LL) % MOD;
		ans = (ans + pp) % MOD;
	}
	for (auto& [a, b] : cy2)
	{
		ans = (ans + (ll)ver[a].size() + (ll)ver[b].size()) % MOD;
	}
	cout << ans;
	return 0;
}