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
		ll n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		bool flag = true;
		ll pivot = v[0];
		for (int i = 1; i < n; ++i)
		{
			if (pivot > v[i])
			{
				flag = false;
				break;
			}
			else
			{
				v[i] = v[i] - pivot;
				pivot = v[i];
			}
		}
		if (flag)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}
