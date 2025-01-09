#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 4;
	vector<vector<bool>>v(102, vector<bool>(102));
	while (T--)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2 ; ++i)
		{
			for (int j = y1; j < y2; ++j)
			{
				v[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (v[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}