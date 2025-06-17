#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v;
	vector<pii>p;
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0;
		cin >> a;
		if (a == 1)
		{
			int b = 0;
			cin >> b;
			p.push_back(make_pair(1, b));
			v.push_back(b);
		}
		else if (a == 2)
		{
			p.push_back(make_pair(2, v.back()));
			v.pop_back();
		}
		else if (a == 3)
		{
			int b = 0;
			cin >> b;
			while (b--)
			{
				if (p.back().first == 1)
				{
					v.pop_back();
				}
				else
				{
					v.push_back(p.back().second);
				}
				p.pop_back();
			}
		}
		else if (a == 4)
		{
			cout << v.size() << '\n';
		}
		else
		{
			cout << ((v.empty()) ? -1 : v.back()) << '\n';
		}
	}
	return 0;
}