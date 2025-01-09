#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	map<int, pii> mm;
	vector<ll> v(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		mm[i] = make_pair(i, i);
		v[i]++;
	}
	while (q--)
	{
		int a = 0;
		cin >> a;
		if (a == 1)
		{
			int b = 0, c = 0;
			cin >> b >> c;
			auto it = mm.upper_bound(b);
			if (it == mm.begin())
			{
				continue;
			}
			--it;
			int left = it->first;
			int right = it->second.second;
			int color = it->second.first;
			if (color == c)
			{
				continue;
			}
			ll len = right - left + 1;
			v[color] -= len;
			v[c] += len;
			mm.erase(it);
			mm[left] = make_pair(c, right);
			auto jt = mm.find(left);
			if (jt != mm.begin())
			{
				auto prev = jt;
				--prev;
				if (prev->second.first == c && prev->second.second + 1 == jt->first)
				{
					int pl = prev->first;
					int pr = jt->second.second;
					mm.erase(prev);
					mm.erase(jt);
					mm[pl] = make_pair(c, pr);
					jt = mm.find(pl);
				}
			}
			auto next = jt;
			++next;
			if (next != mm.end())
			{
				if (next->second.first == c && jt->second.second + 1 == next->first)
				{
					int pl = jt->first;
					int pr = next->second.second;
					mm.erase(next);
					mm.erase(jt);
					mm[pl] = make_pair(c, pr);
					jt = mm.find(pl);
				}
			}
		}
		else
		{
			int b = 0;
			cin >> b;
			cout << v[b] << '\n';
		}
	}
	return 0;
}
