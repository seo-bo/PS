#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll ans = 0, now = 0;
	set<int>tree;
	auto cal = [&]
		{
			while (!tree.empty())
			{
				auto it = tree.lower_bound(now);
				if (it == tree.begin())
				{
					ans += llabs(now - *it);
					now = *it;
					tree.erase(*it);
				}
				else if (it == tree.end())
				{
					it = prev(it);
					ans += llabs(now - *it);
					now = *it;
					tree.erase(*it);
				}
				else
				{
					auto jt = prev(it);
					ll pivot1 = llabs(now - *it), pivot2 = llabs(now - *jt);
					if (pivot1 > pivot2)
					{
						ans += pivot2;
						now = *jt;
						tree.erase(*jt);
					}
					else if (pivot1 < pivot2)
					{
						ans += pivot1;
						now = *it;
						tree.erase(*it);
					}
					else
					{
						ans += pivot1;
						ll p = min(*it, *jt);
						now = p;
						tree.erase(p);
					}
				}
			}
		};
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a == 1)
		{
			int b = 0;
			cin >> b;
			tree.insert(b);
		}
		if (a == 2)
		{
			cal();
		}
	}
	cout << ans;
	return 0;
}