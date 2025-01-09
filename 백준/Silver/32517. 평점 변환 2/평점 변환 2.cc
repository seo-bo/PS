#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>b(n), a;
	for (auto& i : b)
	{
		cin >> i;
	}
	ll sum = 0;
	for (ll i = 1; i <= n; ++i)
	{
		ll temp = b[i - 1];
		if (i == 1)
		{
			if (temp < 1 || temp > 1000000000)
			{
				cout << -1;
				return 0;
			}
			a.push_back(temp);
			sum += temp;
		}
		else
		{
			bool check1 = false;
			if (temp >= 1 && temp <= 1000000000)
			{
				ll p = temp * (i - 1);
				if (p >= sum)
				{
					check1 = true;
				}
			}
			bool check2 = false;
			ll pivot = temp + 1;
			if (pivot >= 1 && pivot <= 1000000000)
			{
				ll p = pivot * (i - 1);
				if (p < sum)
				{
					check2 = true;
				}
			}
			if (check1)
			{
				a.push_back(temp);
				sum += temp;
			}
			else if (check2)
			{
				a.push_back(pivot);
				sum += pivot;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
}