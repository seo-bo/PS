#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		bool check1 = false,check2 = false;
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == '.')
			{
				cnt1++;
			}
			else
			{
				if (cnt1 >= 2)
				{
					a++;
				}
				cnt1 = 0;
			}
		}
		if (cnt1 >= 2)
		{
			a++;
		}
		for (int j = 0; j < n; ++j)
		{
			if (v[j][i] == '.')
			{
				cnt2++;
			}
			else
			{
				if (cnt2 >= 2)
				{
					b++;
				}
				cnt2 = 0;
			}
		}
		if (cnt2 >= 2)
		{
			b++;
		}
	}
	cout << a << ' ' << b;
	return 0;
}