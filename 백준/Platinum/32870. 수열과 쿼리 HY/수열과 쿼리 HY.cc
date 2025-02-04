#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>v(n);
	bool even = false, odd = false;
	for (auto& i : v)
	{
		cin >> i;
		if (i % 2)
		{
			odd = true;
		}
		else
		{
			even = true;
		}
	}
	sort(v.begin(), v.end());
	vector<pii>ans(300001, make_pair(-1, -1));
	ans[1] = make_pair(0, 0);
	if (even && odd)
	{
		ans[2] = make_pair(0, 1);
	}
	else if (even)
	{
		ans[2] = make_pair(0, 0);
	}
	else
	{
		ans[2] = make_pair(1, 1);
	}
	ll ed = v.back();
	while (q--)
	{
		int a = 0;
		cin >> a;
		if (ans[a].first != -1)
		{
			cout << ans[a].first << ' ' << ans[a].second << '\n';
			continue;
		}
		int x = a, ans1 = min(v[0] % a, v[n - 1] % a), ans2 = max(v[0] % a, v[n - 1] % a);
		while (x <= ed)
		{
			auto it = lower_bound(v.begin(), v.end(), x);
			if (it != v.begin())
			{
				ans1 = min(ans1, *prev(it) % a);
				ans2 = max(ans2, *prev(it) % a);
			}
			if (it != v.end())
			{
				ans1 = min(ans1, *it % a);
				ans2 = max(ans2, *it % a);
			}
			if (next(it) != v.end())
			{
				ans1 = min(ans1, *next(it) % a);
				ans2 = max(ans2, *next(it) % a);
			}
			int pivot = *it / a;
			x = (pivot + 1) * a;
		}
		cout << ans1 << ' ' << ans2 << '\n';
		ans[a] = make_pair(ans1, ans2);
	}
	return 0;
}
