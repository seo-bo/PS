#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<bool>prime(100002, true);
	for (int i = 2; i * i <= 100000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		for (int i = 2; i <= 100000; ++i)
		{
			if (n == 1)
			{
				break;
			}
			if (prime[i])
			{
				int cnt = 0;
				while (n != 1 && !(n % i))
				{
					cnt++;
					n /= i;
				}
				if (cnt)
				{
					cout << i << ' ' << cnt << '\n';
				}
			}
		}
	}
	return 0;
}