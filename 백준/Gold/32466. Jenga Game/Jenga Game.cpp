#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	auto cal = [&] (string a)
		{
			if (a == "111")
			{
				return 2;
			}
			else if (a == "110" || a == "011")
			{
				return 1;
			}
			return 0;
		};
	while (T--)
	{
		int n = 0;
		cin >> n;
		ll pivot = 0;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			if (i == 0)
			{
				continue;
			}
			pivot ^= cal(str);
		}
		if (pivot)
		{
			cout << "Yesyes" << '\n';
		}
		else
		{
			cout << "Nono" << '\n';
		}
	}
	return 0;
}