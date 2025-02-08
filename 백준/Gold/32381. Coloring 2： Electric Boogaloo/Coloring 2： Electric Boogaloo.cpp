#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	/*
	단순히 늘리기만 하는거 말고, 줄이는거도 생각을 해야함.
	상대말(행 -> 열 / 열 ->행)이 반 이상 있거나 아니거나 케이스 나눠서 현재말을 조정해서 목표치에 다가가야함.
	*/
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, now = 0, r = 0, c = 0;
	cin >> n >> m;
	bool flag = false;
	vector<pair<char, ll>> ans;
	auto fail = [&]
		{
			cout << -1;
			exit(0);
		};
	auto check1 = [&](ll& a, ll& b, char p)
		{
			if (a <= n / 2 && b < n)
			{
				ans.push_back(make_pair(p, ++b));
			}
			else if (a > n / 2 && b > 0)
			{
				ans.push_back(make_pair(p, b--));
			}
			else
			{
				fail();
			}
		};
	auto check2 = [&](ll& a, ll& b, char p)
		{
			if (a <= n / 2 && b > 0)
			{
				ans.push_back(make_pair(p, b--));
			}
			else if (a > n / 2 && b < n)
			{
				ans.push_back(make_pair(p, ++b));
			}
			else
			{
				fail();
			}
		};
	for (int i = 0; i < m; ++i)
	{
		ll a = 0;
		cin >> a;
		ll pivot = a - now;
		flag = pivot > 0;
		pivot = llabs(pivot);
		if (llabs(n - 2LL * c) == pivot)
		{
			flag ? check1(c, r, 'R') : check2(c, r, 'R');
		}
		else if (llabs(n - 2LL * r) == pivot)
		{
			flag ? check1(r, c, 'C') : check2(r, c, 'C');
		}
		else
		{
			fail();
		}
		now = a;
	}
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}