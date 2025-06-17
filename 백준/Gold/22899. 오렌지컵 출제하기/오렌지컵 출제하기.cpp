#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<pll>v(n);
	for (auto& [_, a] : v)
	{
		cin >> a;
	}
	for (auto& [a, _] : v)
	{
		cin >> a;
	}
	sort(v.begin(), v.end());
	map<int, set<int>>mm;
	vector<priority_queue<ll>>siz(n + 1);
	int idx = 0, cnt = k;
	ll res = 0;
	vector<ll>ans(n + 1, -1);
	while (idx < k)
	{
		auto [a, b] = v[idx];
		res += v[idx].first;
		siz[v[idx].second].push(v[idx].first);
		idx++;
	}
	ans[n] = res;
	for (int i = 1; i <= n; ++i)
	{
		if (!siz[i].empty())
		{
			mm[(int)siz[i].size()].insert(i);
		}
	}
	for (int i = n - 1; i >= 1; --i)
	{
		for (auto& j : mm[i + 1])
		{
			res -= siz[j].top();
			siz[j].pop();
			mm[i].insert(j);
			cnt--;
		}
		mm.erase(i + 1);
		while (idx < n && cnt < k)
		{
			auto [a, b] = v[idx]; // data, idx
			if ((int)siz[b].size() < i)
			{
				int len = siz[b].size();
				mm[len].erase(b);
				mm[len + 1].insert(b);
				siz[b].push(a);
				cnt++;
				res += a;
			}
			idx++;
		}
		if (cnt == k)
		{
			ans[i] = res;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}