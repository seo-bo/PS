#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<ll>used(n + 1, -1); // 포트번호, 꽂혀있는거
	set<ll>unused;
	for (int i = 1; i <= n; ++i)
	{
		unused.insert(i);
	}
	for (int i = 1; i <= q; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			if (unused.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			if (unused.find(b) != unused.end()) // 안쓴거에 있다면
			{
				unused.erase(b);
				used[b] = i;
				cout << b << '\n';
			}
			else
			{
				auto it = unused.lower_bound(b);
				if (it == unused.end())
				{
					cout << -1 << '\n';
					continue;
				}
				cout << *it << '\n';
				used[*it] = i;
				unused.erase(*it);
			}
		}
		else
		{
			if (used[b] == -1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << used[b] << '\n';
				unused.insert(b);
				used[b] = -1;
			}
		}
	}
	return 0;
}
