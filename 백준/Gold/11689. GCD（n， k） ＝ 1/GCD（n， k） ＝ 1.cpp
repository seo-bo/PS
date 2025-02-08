#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void get_prime(ll num)
{
	ll result = num;
	for (ll i = 2; i <= sqrt(num) + 1; ++i)
	{
		if (!(num % i))
		{
			while (!(num % i))
			{
				num /= i;
			}
			result -= (result / i); // n*(1-(1/p1))*(1-(1/p2)).... 니까
		}
	}
	if (num > 1)
	{
		result -= (result / num);
	}
	/********************************************
	result를 1로 두었을때
	ll result = 1;
	for (ll i = 2; i <= sqrt(num) + 1; ++i)
	{
		if (!(num % i))
		{
			num /= i;
			while (!(num % i))
			{
				result *= i;
				num /= i;
			}
			result *= (i - 1);
		}
	}
	if (num > 1)
	{
		result *= (num - 1);
	}
	*******************************************/
	cout << result << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num = 0;
	cin >> num;
	get_prime(num);
	return 0;
}