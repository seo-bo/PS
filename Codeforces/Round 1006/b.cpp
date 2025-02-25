#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		ll a = 0, b = 0;
		string str;
		cin >> str;
		for (auto& i : str)
		{
			if (i == '-')
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		ll base = a;
		a /= 2;
		cout << (base - a) * a * b << '\n';
	}
	return 0;
}
