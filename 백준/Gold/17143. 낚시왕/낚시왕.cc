#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<int, int, int, int, int>tii;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int R = 0, C = 0, m = 0;
	cin >> R >> C >> m;
	ll ans = 0;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,1},{0,-1} };
	unordered_map<int, tii>sharks;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		cin >> a >> b >> c >> d >> e;
		sharks[(a - 1) * C + (b - 1)] = make_tuple(a - 1, b - 1, c, d - 1, e);
	}
	auto solve = [&]()
		{
			unordered_map<int, tii>nshark;
			for (auto [i, j] : sharks)
			{
				auto [x, y, s, d, z] = j;
				int sp = s;
				if (d == 0 || d == 1) // 위 아래
				{
					sp %= (R - 1) * 2;
					if (d == 0)
					{
						if (sp <= x)
						{
							x -= sp;
						}
						else
						{
							sp -= x;
							x = 0, d = 1;
							if (sp <= R - 1)
							{
								x += sp;
							}
							else
							{
								sp -= R - 1;
								x = R - 1 - sp, d = 0;
							}
						}
					}
					else
					{
						if (sp <= R - 1 - x)
						{
							x += sp;
						}
						else
						{
							sp -= (R - 1 - x);
							x = R - 1, d = 0;
							if (sp <= R - 1)
							{
								x -= sp;
							}
							else
							{
								sp -= R - 1;
								x = sp, d = 1;
							}
						}
					}
				}
				else // 왼 오
				{
					sp %= (C - 1) * 2;
					if (d == 3)
					{
						if (sp <= y)
						{
							y -= sp;
						}
						else
						{
							sp -= y;
							y = 0, d = 2;
							if (sp <= C - 1)
							{
								y += sp;
							}
							else
							{
								sp -= C - 1;
								y = C - 1 - sp, d = 3;
							}
						}
					}
					else
					{
						if (sp <= C - 1 - y)
						{
							y += sp;
						}
						else
						{
							sp -= (C - 1 - y);
							y = C - 1, d = 3;
							if (sp <= C - 1)
							{
								y -= sp;
							}
							else
							{
								sp -= C - 1;
								y = sp, d = 2;
							}
						}
					}
				}
				int np = x * C + y;
				if (nshark.find(np) == nshark.end() || get<4>(nshark[np]) < z)
				{
					nshark[np] = make_tuple(x, y, s, d, z);
				}
			}
			swap(sharks, nshark);
		};
	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			int p = j * C + i;
			if (sharks.find(p) != sharks.end())
			{
				ans += get<4>(sharks[p]);
				sharks.erase(p);
				break;
			}
		}
		solve();
	}
	cout << ans;
	return 0;
}