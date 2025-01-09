#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	string str;
	int cnt = 1;
	while (T--)
	{
		ll n = 0, m = 0, k = 0, q = 0;
		for (int i = 0; i < 5; ++i)
		{
			string temp;
			cin >> temp;
			if (i == 2)
			{
				n = stoll(temp);
			}
			if (i == 4)
			{
				m = stoll(temp);
			}
		}
		n--;
		m--;
		for (int i = 0; i < 2; ++i)
		{
			string temp;
			cin >> temp;
			if (i == 0)
			{
				k = stoll(temp);
			}
		}
		map<ll, ll>block;
		for (int i = 0; i < k; ++i)
		{
			ll a = 0, b = 0;
			for (int j = 0; j < 6; ++j)
			{
				string temp;
				cin >> temp;
				if (j == 0)
				{
					a = stoll(temp);
				}
				if (j == 3)
				{
					b = stoll(temp);
				}
			}
			block[b] = n - a + 1;
		}
		for (int i = 0; i < 2; ++i)
		{
			string temp;
			cin >> temp;
			if (i == 0)
			{
				q = stoll(temp);
			}
		}
		vector<string>query(q);
		for (auto& i : query)
		{
			cin >> i;
		}
		cout << format("Case: {}\n", cnt++);
		auto dir = [&](char a)
			{
				if (a == '>')
				{
					return make_pair(0, 1);
				}
				else if (a == '^')
				{
					return make_pair(-1, 1);
				}
				else
				{
					return make_pair(1, 1);
				}
			};
		auto sv = [&](string pivot)
			{
				int x = 0, y = 0;
				for (auto& i : pivot)
				{
					pii pos = dir(i);
					int nx = x + pos.first;
					int ny = y + pos.second;
					if (nx < 0)
					{
						cout << format("Sequence {} Crashed into tunnel ceiling\n", pivot);
						return;
					}
					else if (nx > n)
					{
						cout << format("Sequence {} Crashed into tunnel floor\n", pivot);
						return;
					}
					if (block.find(ny) != block.end() && block[ny] <= nx)
					{
						cout << format("Sequence {} Crashed into stalagmite\n", pivot);
						return;
					}
					if (ny == m)
					{
						cout << format("Sequence {} Reached end of tunnel\n", pivot);
						return;
					}
					x = nx;
					y = ny;
				}
			};
		for (auto& i : query)
		{
			sv(i);
		}
	}
	return 0;
}
