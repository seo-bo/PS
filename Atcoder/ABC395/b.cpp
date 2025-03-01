#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n, '.'));
	for (int i = 1; i <= n; ++i)
	{
		int pivot = n + 1 - i;
		if (i <= pivot)
		{
			char a = '.';
			if (i % 2)
			{
				a = '#';
			}
			for (int j = i - 1; j < pivot; ++j)
			{
				for (int k = i - 1; k < pivot; ++k)
				{
					v[j][k] = a;
				}
			}
		}
	}
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}
