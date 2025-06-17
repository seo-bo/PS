#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<int>>v(n);
	for (auto& i : v)
	{
		string str;
		cin >> str;
		for (auto& j : str)
		{
			i.push_back((j == 'T'));
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << k); ++i)
	{
		int temp = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			int sum = 0;
			for (int z = 0; z < k; ++z)
			{
				if (v[j][z] == ((i >> z) & 1))
				{
					sum++;
				}
			}
			temp = min(temp, sum);
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}