#include <bits/stdc++.h>
#include <unordered_set>
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

	int n = 0, m = 0;
	cin >> n >> m;
	vector<ti>v(m);
	set<pii>ss;
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
		ss.insert(make_pair(a, b));
	}
	auto cal = [&](int x1, int y1, int x2, int y2)
		{
			if (x2 < x1 && y2 == y1)
			{
				return 1;
			}
			if (x2 < x1 && y2 > y1)
			{
				return 2;
			}
			if (x2 == x1 && y2 > y1)
			{
				return 3;
			}
			if (x2 > x1 && y2 > y1)
			{
				return 4;
			}
			if (x2 > x1 && y2 == y1)
			{
				return 5;
			}
			if (x2 > x1 && y2 < y1)
			{
				return 6;
			}
			if (x2 == x1 && y2 < y1)
			{
				return 7;
			}
			if (x2 < x1 && y2 < y1)
			{
				return 8;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (ss.find(make_pair(i, j)) != ss.end())
			{
				continue;
			}
			bool check = true;
			for (auto& [a, b, c] : v)
			{
				if (c != cal(a, b, i, j))
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}
