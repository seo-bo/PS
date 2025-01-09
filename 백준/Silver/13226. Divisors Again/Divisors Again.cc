#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	auto get = [&](const int& n)
		{
			int cnt = 0;
			for (int i = 1; i * i <= n; ++i)
			{
				if (!(n % i))
				{
					if (i * i == n)
					{
						cnt++;
					}
					else
					{
						cnt += 2;
					}
				}
			}
			return cnt;
		};
	int N = 0;
	cin >> N;
	while (N--)
	{
		int L = 0, U = 0;
		cin >> L >> U;
		int result = 0;
		for (int i = L; i <= U; ++i)
		{
			result = max(result, get(i));
		}
		cout << result << "\n";
	}
	return 0;
}