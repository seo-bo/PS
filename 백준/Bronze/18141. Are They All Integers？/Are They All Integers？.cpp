#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (i == j || i == k || j == k)
				{
					continue;
				}
				int a = v[i] - v[j];
				if (a % v[k])
				{
					cout << "no";
					return 0;
				}
			}
		}
	}
	cout << "yes";
	return 0;
}