#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1)
	{
		ll n = 0, sum = 0;
		cin >> n;
		if (n == -1)
		{
			break;
		}
		vector<ll>div;
		for (int i = 1; i <= n / 2; ++i)
		{
			if (n % i == 0)
			{
				div.push_back(i);
				sum += i;
			}
		}
		if (sum != n)
		{
			cout << format("{} is NOT perfect.\n", n);
			continue;
		}
		int len = div.size();
		cout << format("{} = ", n);
		for (int i = 0; i < len; ++i)
		{
			cout << div[i];
			if (i != len - 1)
			{
				cout << " + ";
			}
		}
		cout << '\n';
	}
	return 0;
}