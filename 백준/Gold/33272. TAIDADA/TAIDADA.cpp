#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<ll>ans;
	unordered_set<ll>visited;
	auto cal = [&](ll start, ll end)
		{
			for (ll i = start; i <= end; ++i)
			{
				if ((ll)ans.size() == n)
				{
					return;
				}
				if (visited.find(i ^ k) != visited.end())
				{
					continue;
				}
				visited.insert(i);
				ans.push_back(i);
			}
		};
	ll ed = min(m, 3LL * n);
	cal(1LL, ed);
	if ((ll)ans.size() < n && ed < m)
	{
		cal(ed + 1, m);
	}
	if ((ll)ans.size() < n)
	{
		cout << -1;
		return 0;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}