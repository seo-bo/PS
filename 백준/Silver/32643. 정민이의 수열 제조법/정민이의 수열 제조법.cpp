#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int>prime(5000001, true);
	prime[0] = prime[1] = false;
	vector<ll>prefix(n + 1, 0);
	prefix[0] = 0, prefix[1] = 1;
	for (int i = 2; i * i <= 5000000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 5000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + (prime[i] ? 1 : 0);
	}
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << '\n';
	}
	return 0;
}