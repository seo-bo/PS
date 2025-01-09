#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool check = true;
	ull n = 0;
	cin >> n;
	if (n <= 4)
	{
		cout << -1;
		return 0;
	}
	auto c = [&](ull& a, ull& s)
		{
			while (1)
			{
				if ((1LL << s) == a)
				{
					break;
				}
				else if ((1LL << s) > a)
				{
					check = false;
					break;
				}
				else
				{
					s++;
				}
			}
			if (!check)
			{
				cout << -1;
				exit(0);
			}
		};
	ull shift = 1, sft = 1;
	c(n, shift);
	c(shift, sft);
	cout << sft + 1 << ' ' << sft + 1 << '\n';
	for (int i = 1; i <= sft; ++i)
	{
		cout << 1 << ' ';
	}
	cout << '\n';
	for (int i = 2; i <= sft; ++i)
	{
		cout << 1 << ' ';
	}
	cout << 2;
	return 0;
}