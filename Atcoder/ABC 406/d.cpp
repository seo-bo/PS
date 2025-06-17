#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	vector<set<int>>row(n + 1), col(m + 1);
	for (int i = 0; i < p; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		row[a].insert(b);
		col[b].insert(a);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			cout << row[b].size() << '\n';
			for (auto& i : row[b])
			{
				col[i].erase(b);
			}
			row[b].clear();
		}
		else
		{
			cout << col[b].size() << '\n';
			for (auto& i : col[b])
			{
				row[i].erase(b);
			}
			col[b].clear();
		}
	}
	return 0;
}
