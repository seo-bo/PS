#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>fact(50005, 1);
	for (ll i = 2; i <= 50000; ++i)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		vector<int>prefix(n + 5);
		map<ll, ll>mm;
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			prefix[a]++;
			prefix[b + 1]--;
		}
		ll ans = 0, cnt = 1;
		for (int i = 1; i <= n; ++i)
		{
			prefix[i] += prefix[i - 1];
			mm[prefix[i]]++;
		}
		int idx = 0;
		for (auto& [a, b] : mm) // 기여도, 횟수
		{
			for (int i = 0; i < b; ++i, ++idx)
			{
				ans = ans + v[idx] * a;
			}
			cnt = (cnt * fact[b]) % MOD;
		}
		cout << format("{} {}\n", ans, cnt);
	}
	return 0;
}