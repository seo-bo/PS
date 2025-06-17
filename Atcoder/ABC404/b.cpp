#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	vector<vector<char>>base(n, vector<char>(n));
	vector<vector<char>>B(n, vector<char>(n));
	for (auto& i : base)
	{
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			i[j] = str[j];
		}
	}
	vector<vector<vector<char>>>ok(4, vector<vector<char>>(n, vector<char>(n)));
	ok[0] = base;
	for (int i = n - 1, p = 0; i >= 0; --i, ++p)
	{
		for (int j = n - 1, pp = 0; j >= 0 && pp < n; --j, ++pp)
		{
			ok[2][p][j] = base[i][pp];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0, pp = n - 1; j < n && pp >= 0; ++j, --pp)
		{
			ok[3][j][i] = base[i][pp];
		}
	}
	for (int i = 0, p = n - 1; i < n; ++i, --p)
	{
		for (int j = 0; j < n; ++j)
		{
			ok[1][j][p] = base[i][j];
		}
	}
	for (auto& i : B)
	{
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			i[j] = str[j];
		}
	}
	int ans = INT_MAX;
	for (int z = 0; z < 4; ++z)
	{
		auto& k = ok[z];
		int temp = z;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (k[i][j] != B[i][j])
				{
					temp++;
				}
			}
		}
		ans = min(ans, temp);
	}
	cout << ans;
	return 0;
}
