#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, p = 0;
	cin >> n >> k >> p;
	map<int, set<int>> v;
	map<int, set<int>> g;
	int size = 0;
	vector<int> visited(n + 1, -1);
	vector<int> base(p + 1);
	for (int i = 1; i <= p; ++i)
	{
		cin >> base[i];
		v[base[i]].insert(i);
	}
	int ans = 0;
	for (int i = 1; i <= p; ++i)
	{
		int pivot = base[i], nxt = 0;
		if (visited[pivot] == -1)
		{
			ans++;
			if (size < k)
			{
				size++;
				auto it = v[pivot].begin();
				v[pivot].erase(it);
				if (v[pivot].empty())
				{
					nxt = 1e9;
					v.erase(pivot);
				}
				else
				{
					nxt = *v[pivot].begin();
				}
				visited[pivot] = nxt;
				g[nxt].insert(pivot);
			}
			else
			{
				auto it = prev(g.end());
				auto jt = it->second.begin();
				int ev = *jt;
				visited[ev] = -1;
				it->second.erase(jt);
				if (it->second.empty())
				{
					g.erase(it);
				}
				auto kt = v[pivot].begin();
				v[pivot].erase(kt);
				if (v[pivot].empty())
				{
					nxt = 1e9;
					v.erase(pivot);
				}
				else
				{
					nxt = *v[pivot].begin();
				}
				visited[pivot] = nxt;
				g[nxt].insert(pivot);
			}
		}
		else
		{
			int od = visited[pivot];
			g[od].erase(pivot);
			if (g[od].empty())
			{
				g.erase(od);
			}
			auto it = v[pivot].begin();
			v[pivot].erase(it);
			if (v[pivot].empty())
			{
				nxt = 1e9;
				v.erase(pivot);
			}
			else
			{
				nxt = *v[pivot].begin();
			}
			visited[pivot] = nxt;
			g[nxt].insert(pivot);
		}
	}
	cout << ans;
	return 0;
}