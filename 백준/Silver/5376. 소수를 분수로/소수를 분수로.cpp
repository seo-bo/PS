#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

string str = "";

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		bool check = false;
		ll demo = 1;
		ll nu = 1;
		ll num = 0;
		ll num2 = 0;
		cin >> str;
		for (auto& i : str)
		{
			if ('0' <= i && i <= '9')
			{
				if (!check)
				{
					nu *= 10;
					num2 = (num2 * 10) + (i - '0');
				}
				num = (num * 10) + (i - '0');
				demo *= 10;
			}
			else if (i == '(')
			{
				check = true;
			}
		}
		if (num == num2 && demo == nu)
		{
			demo /= 10;
			ll temp = gcd(num, demo);
			cout << num / temp << "/" << demo / temp << "\n";
		}
		else
		{
			demo /= 10; nu /= 10;
			ll temp = gcd(num - num2, demo - nu);
			cout << (num - num2) / temp << "/" << (demo - nu) / temp << "\n";
		}
	}
	return 0;
}