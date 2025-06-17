#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, cnt = 0;
	cin >> n;
	vector<ll>w(n), p(n);
	for (auto& i : w)
	{
		cin >> i;
	}
	map<ll, ll>mm;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		if (mm.find(p[i]) == mm.end())
		{
			mm[p[i]] = cnt++;
		}
	}
	vector<vector<ll>>v(cnt);
	for (int i = 0; i < n; ++i)
	{
		v[mm[p[i]]].push_back(w[i] * (5000 - p[i]));
	}
	int left = cnt / 2, right = cnt - left;
	ll ans = 0;
	map<ll, ll>ok;
	function<void(int, ll)> lft = [&](int idx, ll sum)
		{
			if (idx == left)
			{
				ok[sum]++;
				return;
			}
			lft(idx + 1, sum);
			for (auto& i : v[idx])
			{
				lft(idx + 1, sum + i);
			}
		};
	lft(0, 0LL);
	function<void(int, ll)> rgt = [&](int idx, ll sum)
		{
			if (idx == cnt)
			{
				ans += ok[-sum];
				return;
			}
			rgt(idx + 1, sum);
			for (auto& i : v[idx])
			{
				rgt(idx + 1, sum + i);
			}
		};
	rgt(left, 0LL);
	cout << ans - 1;
	return 0;
}