#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	auto power = [&](lint x, lint y, lint exp) -> ull
		{
			lint ans = 1;
			x %= exp;
			while (y > 0)
			{
				if (y % 2 == 1)
				{
					ans = (ans * x) % exp;
				}
				x = (x * x) % exp;
				y /= 2;
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
				if (k % 2 == 1)
				{
					return (temp == 1 || temp == a - 1);
				}
				k /= 2;
			}
		};
	auto pr = [&](ull a) -> bool
		{
			if (a == 2 || a == 3)
			{
				return true;
			}
			if (a % 2 == 0 || a < 2)
			{
				return false;
			}
			vector<ull> prime = { 2, 7, 61 };
			for (auto& i : prime)
			{
				if (a == i)
				{
					return true;
				}
				if (!miller_rabin(a, i))
				{
					return false;
				}
			}
			return true;
		};
	int n = 0, ans = 0;
	cin >> n;
	while (n--)
	{
		ull temp = 0;
		cin >> temp;
		if (pr(temp * 2 + 1))
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}