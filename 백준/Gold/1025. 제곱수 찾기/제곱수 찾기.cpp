#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	auto check = [&](int x, int y)
		{
			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				return true;
			}
			return false;
		};
	auto cal = [&](ll base)
		{
			ll left = 0, right = 1e6;
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if (mid * mid == base)
				{
					return true;
				}
				if (mid * mid > base)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			return false;
		};
	vector<vector<char>>v(n, vector<char>(m));
	ll ans = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = -10; k <= 10; ++k)
			{
				for (int z = -10; z <= 10; ++z)
				{
					string temp = "";
					temp += v[i][j];
					int x = i, y = j;
					vector<string>ok = { temp };
					if (k == 0 && z == 0)
					{
						if (cal(stoll(temp)))
						{
							ans = max(ans, stoll(temp));
						}
						continue;
					}
					while (1)
					{
						int nx = x + k;
						int ny = y + z;
						if (check(nx, ny))
						{
							x = nx;
							y = ny;
							temp += v[x][y];
							ok.push_back(temp);
							continue;
						}
						break;
					}
					for (auto& i : ok)
					{
						ll num = stoll(i);
						if (cal(num))
						{
							ans = max(ans, num);
						}
					}
				}
			}
		}
	}
	cout << ((ans == INT_MIN) ? -1 : ans);
	return 0;
}