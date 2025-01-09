#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<int, set<int>>mm;
	unordered_map<int, int>prob;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		mm[b].insert(a);
		prob[a] = b;
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		if (str == "recommend")
		{
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				auto it = prev(mm.end());
				cout << *(prev((*it).second.end())) << '\n';
			}
			else
			{
				auto it = mm.begin();
				cout << *((*it).second.begin()) << '\n';
			}
		}
		else if (str == "add")
		{
			int a = 0, b = 0;
			cin >> a >> b;
			prob[a] = b;
			mm[b].insert(a);
		}
		else
		{
			int a = 0;
			cin >> a;
			int lev = prob[a];
			prob.erase(a);
			mm[lev].erase(a);
			if (mm[lev].empty())
			{
				mm.erase(lev);
			}
		}
	}
	return 0;
}