#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll>v;
ll a = 0, b = 0, L = 0, tempL = 0;
void get()
{
	for (int i = 1; i <= tempL; ++i)
	{
		if (L % i == 0)
		{
			v.push_back(i);
			v.push_back(L / i);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> L;
	tempL = sqrt(L) + 1;
	ll LCM = lcm(a, b);
	if (LCM == L)
	{
		cout << 1;
		return 0;
	}
	if (L % LCM != 0)
	{
		cout << -1;
		return 0;
	}
	get();
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		if (lcm(LCM, i) == L)
		{
			cout << i;
			return 0;
		}
	}
}