#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 lint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll a = 0, b = 0, c = 0, d = 0;
	//cin >> a >> b >> c >> d;
	map<ull, ull> div;
	vector<ll>divisor;
	vector<pll> ans;
	auto zero = [&]
		{
			cout << 0;
			exit(0);
		};
	auto inf = [&]
		{
			cout << "INFINITY";
			exit(0);
		};
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
			vector<ull> prime = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
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
	function<void(ull, map<ull, ull>::iterator)> finddiv = [&](ull dvs, map<ull, ull>::iterator it)
		{
			if (it == div.end())
			{
				divisor.push_back(dvs);
				return;
			}
			ull base = it->first, exp = it->second, pro = dvs;
			for (ull i = 0; i <= exp; ++i)
			{
				finddiv(pro, next(it));
				pro *= base;
			}
		};
	auto find = [&](ll x, ll xx, ll y, ll yy, ll pivot, ll divs) // x 
		{
			pll input;
			ll divs2 = pivot / divs;
			ll n1 = divs - xx;
			if (n1 % x)
			{
				return;
			}
			input.first = n1 / x;
			ll n2 = divs2 - yy;
			if (n2 % y)
			{
				return;
			}
			input.second = n2 / y;
			ans.push_back(input);
		};
	cin >> a;
	cal(a);
	for (auto& [i, j] : div)
	{
		for (int k = 0; k < j; ++k)
		{
			cout << i << '\n';
		}
	}
	return 0;
	if (a && b && c && d) // 검사[C#1]
	{
		// (ax + c) (y + (b /a )) = p1
		ll p1 = b * c;
		if (p1 % a)
		{
			zero();
		}
		p1 /= a;
		if (!(p1 - d))
		{
			inf();
		}
		if (b % a)
		{
			zero();
		}
		b = b / a;
		p1 -= d;
		ll pp = llabs(p1);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, c, 1, b, p1, i);
		}
		for (auto& i : divisor)
		{
			find(a, c, 1, b, p1, -i);
		}
	}
	else if (!a && b && c && d)//[C#2]
	{
		b = llabs(b), c = llabs(c), d = llabs(d);
		ll pivot = gcd(b, c);
		if (pivot == 1)
		{
			inf();
		}
		else
		{
			if (!(llabs(d) % pivot))
			{
				inf();
			}
			else
			{
				zero();
			}
		}
	}
	else if (a && !b && c && d) // 검사 [C#3]
	{
		// (x + (c/a))(ay) = -d;
		if (c % a)
		{
			zero();
		}
		c /= a;
		ll pp = llabs(d);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(1, c, a, 0, -d, i);
		}
		for (auto& i : divisor)
		{
			find(1, c, a, 0, -d, -i);
		}
	}
	else if (a && b && !c && d) // 검사 (C#3 동일) [C#4]
	{
		// (ax)(y + (b/a)) = -d 
		if (b % a)
		{
			zero();
		}
		b /= a;
		ll pp = llabs(d);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, 0, 1, b, -d, i);
		}
		for (auto& i : divisor)
		{
			find(a, 0, 1, b, -d, i);
		}
	}
	else if (a && b && c && !d) // 검사 (C#1 동일) [C#5]
	{
		// (ax + c) (y + b) = p1
		if (b % a)
		{
			zero();
		}
		ll p1 = b * c;
		if (p1 % a)
		{
			zero();
		}
		p1 /= a;
		b /= a;
		ll pp = llabs(p1);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, c, 1, b, p1, i);
		}
		for (auto& i : divisor)
		{
			find(a, c, 1, b, p1, -i);
		}
	}
	else if (!a && !b && c && d)// [C#6]
	{
		if (d % c)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (!a && b && !c && d) // [C#7]
	{
		if (d % b)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (!a && b && c && !d) // [C#8]
	{
		inf();
	}
	else if (a && !b && !c && d) // 검사 [C#9]
	{
		// xy = -(d/c)
		if (d % a)
		{
			zero();
		}
		d /= a;
		ll pp = llabs(d);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(1, 0, 1, 0, -d, i);
		}
		for (auto& i : divisor)
		{
			find(1, 0, 1, 0, -d, -i);
		}
	}
	else if (a && !b && c && !d) // [C#10]
	{
		if (c % a)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (a && b && !c && !d) // [C#11]
	{
		if (b % a)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (!a && !b && !c && d) // [C#12]
	{
		zero();
	}
	else // [C#13 ~ C#16]
	{
		inf();
	}
	sort(ans.begin(), ans.end(), [&](const pll& a, const pll& b)
		{
			if (a.first == b.first)
			{
				return a.second < b.second;
			}
			return a.first < b.first;
		});
	cout << ans.size() << '\n';
	for (auto& [i, j] : ans)
	{
		cout << i << ' ' << j << '\n';
	}
	return 0;
}