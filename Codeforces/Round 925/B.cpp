#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		ll sum = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
			sum += i;
		}
		if (n == 1)
		{
			cout << "yes" << '\n';
			continue;
		}
		sum /= n;
		bool check = true;
		for (int i = 0; i < n - 1; ++i)
		{
			if (v[i] >= sum)
			{
				ll target = v[i] - sum;
				v[i] = sum;
				v[i + 1] += target;
			}
			else
			{
				check = false;
				break;
			}
		}
		if (check && v[n-1] == sum)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
	return 0;
}
