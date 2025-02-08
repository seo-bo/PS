#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto c = [&](int x, int y, vector<int>& t)
		{
			int m1 = INT_MIN, m2 = INT_MIN;
			for (int i = x; i < x + 2; ++i)
			{
				for (int j = y; j < y + 2; ++j)
				{
					if (v[i][j] > m1)
					{
						swap(m1, m2);
						m1 = v[i][j];
					}
					else if (v[i][j] > m2)
					{
						m2 = v[i][j];
					}
				}
			}
			t.push_back(m2);
		};
	function<void(int)> sv = [&](int siz)
		{
			vector<int>temp;
			if (siz == 1)
			{
				cout << v[0][0];
				exit(0);
			}
			for (int i = 0; i < siz; i += 2)
			{
				for (int j = 0; j < siz; j += 2)
				{
					c(i, j, temp);
				}
			}
			int pivot = siz / 2, idx = 0;
			for (int i = 0; i < pivot; ++i)
			{
				for (int j = 0; j < pivot; ++j)
				{
					v[i][j] = temp[idx++];
				}
			}
			sv(pivot);
		};
	sv(n);
	return 0;
}