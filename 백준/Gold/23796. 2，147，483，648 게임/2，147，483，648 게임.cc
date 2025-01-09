#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	unordered_map<char, int>m = { {'U',0},{'D',1},{'L',2},{'R',3} };
	vector<vector<ll>>v(8, vector<ll>(8, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto move = [&](char a)
		{
			vector<vector<ll>>temp(8, vector<ll>(8, 0));
			if (a == 'U')
			{
				for (int j = 0; j < 8; ++j)
				{
					deque<ll>dq;
					for (int i = 0; i < 8; ++i)
					{
						if (v[i][j])
						{
							dq.push_back(v[i][j]);
						}
					}
					int x = 0, y = j;
					while (!dq.empty())
					{
						ll pivot = 0;
						if (dq.size() > 1 && dq[0] == dq[1])
						{
							pivot = dq.front() * 2;
							dq.pop_front();
							dq.pop_front();
						}
						else
						{
							pivot = dq.front();
							dq.pop_front();
						}
						temp[x++][y] = pivot;
					}
				}
			}
			else if (a == 'D')
			{
				for (int j = 0; j < 8; ++j)
				{
					deque<ll>dq;
					for (int i = 7; i >= 0; --i)
					{
						if (v[i][j])
						{
							dq.push_back(v[i][j]);
						}
					}
					int x = 7, y = j;
					while (!dq.empty())
					{
						ll pivot = 0;
						if (dq.size() > 1 && dq[0] == dq[1])
						{
							pivot = dq.front() * 2;
							dq.pop_front();
							dq.pop_front();
						}
						else
						{
							pivot = dq.front();
							dq.pop_front();
						}
						temp[x--][y] = pivot;
					}
				}
			}
			else if (a == 'L')
			{
				for (int i = 0; i < 8; ++i)
				{
					deque<ll>dq;
					for (int j = 0; j < 8; ++j)
					{
						if (v[i][j])
						{
							dq.push_back(v[i][j]);
						}
					}
					int x = i, y = 0;
					while (!dq.empty())
					{
						ll pivot = 0;
						if (dq.size() > 1 && dq[0] == dq[1])
						{
							pivot = dq.front() * 2;
							dq.pop_front();
							dq.pop_front();
						}
						else
						{
							pivot = dq.front();
							dq.pop_front();
						}
						temp[x][y++] = pivot;
					}
				}
			}
			else
			{
				for (int i = 0; i < 8; ++i)
				{
					deque<ll>dq;
					for (int j = 7; j >= 0; --j)
					{
						if (v[i][j])
						{
							dq.push_back(v[i][j]);
						}
					}
					int x = i, y = 7;
					while (!dq.empty())
					{
						ll pivot = 0;
						if (dq.size() > 1 && dq[0] == dq[1])
						{
							pivot = dq.front() * 2;
							dq.pop_front();
							dq.pop_front();
						}
						else
						{
							pivot = dq.front();
							dq.pop_front();
						}
						temp[x][y--] = pivot;
					}
				}
			}
			v = temp;
		};
	char p;
	cin >> p;
	move(p);
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}