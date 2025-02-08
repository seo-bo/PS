#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __int128 lint;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ull a = 0, b = 0;
	cin >> a >> b;
	for (ull n = a; n <= b; ++n)
	{
		if (n % 2 == 0)
		{
			continue;
		}
		auto power = [&](lint x, lint y, lint exp) -> ull
			{
				lint ans = 1;
				x %= exp;
				while (y > 0)
				{
					if (y & 1)
					{
						ans = (ans * x) % exp;
					}
					x = (x * x) % exp;
					y >>= 1;
				}
				return (ull)ans;
			};
		auto miller_rabin = [&](ull a, ull b) -> bool
			{
				if (b % a == 0)
				{
					return true;
				}
				ull k = a - 1;
				while (1)
				{
					ull temp = power(b, k, a);
					if (temp == a - 1)
					{
						return true;
					}
					if (k & 1)
					{
						return (temp == 1 || temp == a - 1);
					}
					k >>= 1;
				}
			};
		auto pr = [&](ull a) -> bool
			{
				if (a == 2 || a == 3)
				{
					return true;
				}
				if (a % 2 == 0)
				{
					return false;
				}
				vector<ull> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
				for (auto& i : prime)
				{
					if (!miller_rabin(a, i))
					{
						return false;
					}
				}
				return true;
			};
		if (pr(n) || n == 9)
		{
			cout << n << ' ';
		}
	}
	return 0;
}