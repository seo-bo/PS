#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		vector<int>a(2), b(2);
		string A, B;
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == 'W')
			{
				a[0]++;
			}
			else
			{
				a[1]++;
			}
			A += v[i][j];
		}
		for (int j = 0; j < n; ++j)
		{
			if (v[j][i] == 'W')
			{
				b[0]++;
			}
			else
			{
				b[1]++;
			}
			B += v[j][i];
		}
		if (b[0] != b[1] || a[0] != a[1])
		{
			cout << 0;
			return 0;
		}
		vector<string>temp = { "WWW","BBB" };
		for (auto& j : temp)
		{
			if (A.find(j) != string::npos || B.find(j) != string::npos)
			{
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
	return 0;
}