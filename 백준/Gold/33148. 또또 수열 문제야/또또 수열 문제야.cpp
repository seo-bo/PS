#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	unordered_map<ll, ll>mm;
	vector<ll>v;
	for (int i = 0; i < n * n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (!mm[temp])
		{
			v.push_back(temp);
		}
		mm[temp]++;
	}
	sort(v.begin(), v.end());
	auto fail = [&]
		{
			cout << "NO";
			exit(0);
		};
	auto check = [&](ll a, ll b)
		{
			if (a > LLONG_MAX / b || mm[a * b] < 0)
			{
				return true;
			}
			return false;
		};
	ll p = (ll)sqrt(v[0]), p1 = v[0];
	mm[p1]--;
	if (check(p, p) || p * p != p1)
	{
		fail();
	}
	vector<ll>ans;
	ans.push_back(p);
	for (auto& i : v)
	{
		while (mm[i] > 0)
		{
			ll pivot = i / p;
			for (auto& j : ans)
			{
				mm[pivot * j] -= 2;
				if (check(pivot, j))
				{
					fail();
				}
			}
			--mm[pivot * pivot];
			if (check(pivot, pivot))
			{
				fail();
			}
			ans.push_back(pivot);
		}
	}
	cout << "YES" << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}