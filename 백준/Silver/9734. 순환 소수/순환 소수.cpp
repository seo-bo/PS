#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	while (getline(cin, str))
	{
		int a = 0, b = 0;
		string tot = "0", base = "0";
		bool f1 = false, f2 = false;
		for (auto& i : str)
		{
			if (i == '(' || i == ')')
			{
				f2 = true;
				continue;
			}
			if (i == '.')
			{
				f1 = true;
				continue;
			}
			tot += i;
			if (!f2)
			{
				base += i;
			}
			if (f1)
			{
				a++;
				if (!f2)
				{
					b++;
				}
			}
		}
		ll pivot = (ll)pow(10, a) - (ll)pow(10, b);
		ll pp = stoi(tot) - stoi(base);
		ll G = gcd(pivot, pp);
		pivot /= G;
		pp /= G;
		cout << format("{} = {} / {}\n", str, pp, pivot);
	}
	return 0;
}