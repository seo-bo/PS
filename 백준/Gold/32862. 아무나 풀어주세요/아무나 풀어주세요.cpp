#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<int>A(n + 1), B(m + 1);
		for (int i = 1; i <= n; ++i)
		{
			cin >> A[i];
		}
		for (int i = 1; i <= m; ++i)
		{
			cin >> B[i];
		}
		bool f = true;
		for (int i = 1; i <= n - 3; ++i)
		{
			if (A[i] != B[i])
			{
				f = false;
				break;
			}
		}
		if (!f)
		{
			cout << "NO" << "\n";
			continue;
		}
		auto key = [&](int a, int b, int c)
			{
				return a * 100 + b * 10 + c;
			};
		vector<bool>dp(1000, false);
		dp[key(B[m - 2], B[m - 1], B[m])] = true;
		for (int i = m - 3; i >= n - 2; --i)
		{
			vector<bool>temp(1000, false);
			for (int j = 111; j <= 999; ++j)
			{
				if (dp[j])
				{
					int a = j / 100, b = (j / 10) % 10, c = j % 10;
					vector<int>per = { B[i], a, b };
					sort(per.begin(), per.end());
					if (c % 2)
					{
						temp[key(B[i], a, b)] = true;
					}
					else
					{
						if (B[i] <= a && a <= b)
						{
							do
							{
								temp[key(per[0], per[1], per[2])] = true;
							} while (next_permutation(per.begin(), per.end()));
						}
					}
				}
			}
			dp = move(temp);
		}
		int pivot = key(A[n - 2], A[n - 1], A[n]);
		if (dp[pivot])
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}