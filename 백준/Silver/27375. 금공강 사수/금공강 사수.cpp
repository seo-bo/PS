#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, ans = 0;
	cin >> n >> k;
	vector<tp>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 5)
		{
			continue;
		}
		v.push_back(make_tuple(a, b, c));
	}
	int len = v.size();
	for (int i = 1; i < (1 << len); ++i)
	{
		vector<vector<int>>prefix(6, vector<int>(15, 0));
		int temp = 0;
		for (int j = 0; j < len; ++j)
		{
			if (i & (1 << j))
			{
				auto [a, b, c] = v[j];
				prefix[a][b]++;
				prefix[a][c + 1]--;
				temp += c - b + 1;
			}
		}
		auto sv = [&]
			{
				if (temp != k)
				{
					return false;
				}
				for (int j = 1; j <= 5; ++j)
				{
					for (int k = 1; k <= 14; ++k)
					{
						prefix[j][k] += prefix[j][k - 1];
						if (prefix[j][k] > 1)
						{
							return false;
						}
					}
				}
				return true;
			};
		if (sv())
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}