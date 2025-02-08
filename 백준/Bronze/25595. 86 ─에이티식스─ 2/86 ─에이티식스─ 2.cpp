#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
			{
				p = i + j;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == 1)
			{
				if ((i + j) % 2 == p % 2)
				{
					cout << "Kiriya";
					return 0;
				}
			}
		}
	}
	cout << "Lena";
	return 0;
}