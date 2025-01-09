#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<int>>v(h, vector<int>(w, -1));
	for (int i = 0; i < h; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; ++j)
		{
			if (str[j] == 'c')
			{
				v[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 1; j < w; ++j)
		{
			if (v[i][j] == -1 && v[i][j - 1] != -1)
			{
				v[i][j] = v[i][j - 1] + 1;
			}
		}
	}
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