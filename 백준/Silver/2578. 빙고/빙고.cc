#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<bool>>check(5, vector<bool>(5, false));
	map<int, pii>m;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int temp = 0;
			cin >> temp;
			m[temp] = make_pair(i, j);
		}
	}
	auto judge = [&]() ->bool
		{
			int cnt = 0;
			for (int i = 0; i < 5; ++i)
			{
				bool wc = true, hc = true;
				for (int j = 0; j < 5; ++j)
				{
					if (!check[i][j])
					{
						wc = false;
						break;
					}
				}
				for (int j = 0; j < 5; ++j)
				{
					if (!check[j][i])
					{
						hc = false;
						break;
					}
				}
				if (wc)
				{
					cnt++;
				}
				if (hc)
				{
					cnt++;
				}
			}
			bool wc = true, hc = true;
			for (int i = 0; i < 5; ++i)
			{
				if (!check[i][i])
				{
					wc = false;
					break;
				}
			}
			for (int i = 4; i >= 0; --i)
			{
				if (!check[i][4 - i])
				{
					hc = false;
					break;
				}
			}
			if (wc)
			{
				cnt++;
			}
			if (hc)
			{
				cnt++;
			}
			return (cnt >= 3) ? true : false;
		};
	for (int i = 0; i < 5 * 5; ++i)
	{
		int temp = 0;
		cin >> temp;
		check[m[temp].first][m[temp].second] = true;
		if (judge())
		{
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}