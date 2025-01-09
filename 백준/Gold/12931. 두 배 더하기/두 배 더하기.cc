#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	auto sv = [&]
		{
			int temp = 0;
			for (auto& i : v)
			{
				if (i % 2)
				{
					i--;
					ans++;
				}
				if (i)
				{
					temp++;
				}
				i /= 2;
			}
			if (temp)
			{
				return true;
			}
			else
			{
				return false;
			}
		};
	while (1)
	{
		if (sv())
		{
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
