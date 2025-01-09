#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef __int128 lint;
typedef long long ll;

// 아래 사이트를 참고했습니당. (라그랑주 네 제곱수 정리)
// https://ko.wikipedia.org/wiki/%EB%9D%BC%EA%B7%B8%EB%9E%91%EC%A3%BC_%EB%84%A4_%EC%A0%9C%EA%B3%B1%EC%88%98_%EC%A0%95%EB%A6%AC
int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ull n = 0;
	cin >> n;
	unordered_map<ull, ull>div;
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
	auto checker1 = [&] // 완전 제곱수는 한수로 표현 가능
		{
			ll x = sqrt(n);
			while (x * x > n)
			{
				x--;
			}
			while ((x + 1) * (x + 1) <= x)
			{
				x++;
			}
			return x * x == n;
		};
	auto checker2 = [&] // 두 수의 합으로 표현하기 위해선 4k+3 꼴인 소인수가 "짝수"개 존재해야함
		{
			for (auto& [a, b] : div)
			{
				if (a % 4 == 3 && b % 2 != 0)
				{
					return false;
				}
			}
			return true;
		};
	auto checker3 = [&] // 4^n(8k+7) 꼴이면 네 수의 합, 아니면 세 수의 합
		{
			ull a = n;
			while (!(a % 4))
			{
				a /= 4;
			}
			return a % 8 != 7;
		};
	cal(n);
	if (checker1())
	{
		cout << 1;
	}
	else if (checker2())
	{
		cout << 2;
	}
	else if (checker3())
	{
		cout << 3;
	}
	else
	{
		cout << 4;
	}
	return 0;
}