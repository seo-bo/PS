#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<bool>prime(1001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(1000); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	vector<int>v;
	for (int i = 2; i <= 1000; ++i)
	{
		if (prime[i])
		{
			v.push_back(i);
		}
	}
	int n = 0, siz = v.size();
	cin >> n;
	while (n--)
	{
		int z = 0;
		cin >> z;
		bool check = false;
		for (int i = 0; !check && i < siz; ++i)
		{
			for (int j = 0; !check && j < siz; ++j)
			{
				for (int k = 0; !check && k < siz; ++k)
				{
					if (v[i] + v[j] + v[k] == z)
					{
						cout << v[i] << ' ' << v[j] << ' ' << v[k] << '\n';
						check = true;
					}
				}
			}
		}
		if (!check)
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}