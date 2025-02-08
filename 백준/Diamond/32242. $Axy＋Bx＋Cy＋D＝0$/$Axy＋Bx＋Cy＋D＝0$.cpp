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
	cin >> a >> b >> c >> d;
	map<ull, ull> div;
	vector<ll>divisor;
	set<pll> ans;
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
	auto GCD = [&](ull a, ull b) -> ull
		{
			if (a < b)
			{
				swap(a, b);
			}
			while (b)
			{
				ull tt = a % b;
				a = b;
				b = tt;
			}
			return a;
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
				d = GCD(abs(a - b), n);
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
			ll aa = (input.first * x + xx) * (input.second * y + yy);
			if (aa == pivot)
			{
				ans.insert(input);
			}
		};
	if (a != 0 && b != 0 && c != 0 && d != 0) // 검사[C#1]
	{
		// (ax+c) (ay+b) = bc - ad
		ll p1 = a * d; // -1
		ll p2 = b * c; // 1
		ll p = p2 - p1;
		if (p == 0)
		{
            if(c % a && b % a)
            {
                zero();
            }
			inf();
		}
		ll pp = llabs(p);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, c, a, b, p, i);
			find(a, c, a, b, p, -i);
			find(a, c, a, b, p, p / i);
			find(a, c, a, b, p, -p / i);
		}
	}
	else if (a == 0 && b != 0 && c != 0 && d != 0)//[C#2]
	{
		// bx + cy = -d
		b = llabs(b), c = llabs(c), d = llabs(d);
		ll pivot = GCD(b, c);
		if (d % pivot == 0)
		{
			inf();
		}
		else
		{
			zero();
		}
	}
	else if (a != 0 && b == 0 && c != 0 && d != 0) // 검사 [C#3]
	{
		// (ax +c) (ay) = -ad
		ll p = -a * d;
		ll pp = llabs(p);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, c, a, 0, p, i);
			find(a, c, a, 0, p, -i);
			find(a, c, a, 0, p, p / i);
			find(a, c, a, 0, p, -p / i);
		}
	}
	else if (a != 0 && b != 0 && c == 0 && d != 0) // 검사 (C#3 동일) [C#4]
	{
		// (ax)(ay+b) = -ad
		ll p = -a * d;
		ll pp = llabs(p);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, 0, a, b, p, i);
			find(a, 0, a, b, p, -i);
			find(a, 0, a, b, p, p / i);
			find(a, 0, a, b, p, -p / i);
		}
	}
	else if (a != 0 && b != 0 && c != 0 && d == 0) // 검사 (C#1 동일) [C#5]
	{
		// (ax+c) (ay+b) = bc
		ll p = b * c;
		ll pp = llabs(p);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, c, a, b, p, i);
			find(a, c, a, b, p, -i);
			find(a, c, a, b, p, p / i);
			find(a, c, a, b, p, -p / i);
		}
	}
	else if (a == 0 && b == 0 && c != 0 && d != 0)// [C#6]
	{
		//cy = - d
		if (d % c != 0)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (a == 0 && b != 0 && c == 0 && d != 0) // [C#7]
	{
		//bx = -d
		if (d % b != 0)
		{
			zero();
		}
		else
		{
			inf();
		}
	}
	else if (a == 0 && b != 0 && c != 0 && d == 0) // [C#8]
	{
		//bx +cy = 0
		inf();
	}
	else if (a != 0 && b == 0 && c == 0 && d != 0) // 검사 [C#9]
	{
		// (ax)(y) = -d
		ll p = -d;
		ll pp = llabs(p);
		cal(pp);
		finddiv(1, div.begin());
		for (auto& i : divisor)
		{
			find(a, 0, 1, 0, p, i);
			find(a, 0, 1, 0, p, -i);
			find(a, 0, 1, 0, p, p / i);
			find(a, 0, 1, 0, p, -p / i);
		}
	}
	else if (a != 0 && b == 0 && c != 0 && d == 0) // [C#10]
	{
		inf();
	}
	else if (a != 0 && b != 0 && c == 0 && d == 0) // [C#11]
	{
		inf();
	}
	else if (a == 0 && b == 0 && c == 0 && d != 0) // [C#12]
	{
		zero();
	}
	else // [C#13 ~ C#16]
	{
		inf();
	}
	cout << ans.size() << '\n';
	for (auto& [i, j] : ans)
	{
		cout << i << ' ' << j << '\n';
	}
	return 0;
}