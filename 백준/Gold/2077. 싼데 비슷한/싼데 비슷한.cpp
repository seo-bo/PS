#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		ll sum = 0;
		vector<ll>v(4);
		for (int i = 1; i <= n; ++i)
		{
			int temp = 0;
			cin >> temp;
			sum += temp;
			if (i == 1)
			{
				continue;
			}
			for (int j = 1; j <= 4; ++j)
			{
				if ((i - j) % 4)
				{
					v[j - 1] += temp;
				}
			}
		}
		if (n <= 4)
		{
			cout << "YES\n0";
			for (int i = 0; i < n - 1; ++i)
			{
				cout << n - 1;
			}
			cout << '\n';
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (sum * 3 <= v[i] * 4)
			{
				cout << "YES\n";
				int idx = 1;
				if (i == 1)
				{
					idx = 2;
					cout << 0;
				}
				else if (i == 2)
				{
					idx = 3;
					cout << "01";
				}
				else if (i == 3)
				{
					idx = 4;
					cout << "022";
				}
				while (idx <= n)
				{
					if (idx + 3 <= n)
					{
						cout << "0333";
						idx += 4;
						continue;
					}
					if (idx + 2 <= n)
					{
						cout << "022";
						idx += 3;
						continue;
					}
					if (idx + 1 <= n)
					{
						cout << "01";
						idx += 2;
						continue;
					}
					if (idx == n)
					{
						cout << "0";
						idx += 1;
						continue;
					}
				}
				cout << '\n';
				break;
			}
		}
	}
	return 0;
}