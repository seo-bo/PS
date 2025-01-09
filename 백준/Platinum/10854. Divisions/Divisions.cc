#include <bits/stdc++.h>
#include <unordered_set>
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
	ll N = 0;
	cin >> N;
	unordered_map<ull, ull> div;
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
	function<ull(lint)> rho = [&](lint n) -> ull
		{
			if (n % 2 == 0)
			{
				return 2;
			}
			if (pr(n))
			{
				return n;
			}
			lint a = rand() % (n - 2) + 2, b = a, c = rand() % 10 + 1, d = 1;
			while (d == 1)
			{
				a = (a * a % n + c) % n;
				b = (b * b % n + c) % n;
				b = (b * b % n + c) % n;
				d = gcd(abs(a - b), n);
				if (d == n)
				{
					return rho(n);
				}
			}
			if (pr(d))
			{
				return d;
			}
			else
			{
				return rho(d);
			}
		};
	auto cal = [&](ull n)
		{
			while (n > 1)
			{
				ull p = rho(n);
				div[p]++;
				n /= p;
			}
		};
	cal(N);
	ull ans = 1;
	for (auto& i : div)
	{
		ans *= (i.second + 1);
	}
	cout << ans << "\n";
	return 0;
}