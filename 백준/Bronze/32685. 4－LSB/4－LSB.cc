#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, lb> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string pivot;
	for (int i = 0; i < 3; ++i)
	{
		ll n = 0, sft = 8;
		cin >> n;
		string str;
		for (int j = 0; j < 4; ++j)
		{
			str += (n & sft) ? '1' : '0';
			sft >>= 1;
		}
		pivot += str;
	}
	ll ans = 0;
	for (int i = 11; i >= 0; --i)
	{
		ll c = pivot[i];
		if (c == '1')
		{
			ans += (1 << (11 - i));
		}
	}
	if (ans == 0)
	{
		cout << "0000";
	}
	else if (ans < 10)
	{
		cout << "000" << ans;
	}
	else if (ans < 100)
	{
		cout << "00" << ans;
	}
	else if (ans < 1000)
	{
		cout << "0" << ans;
	}
	else
	{
		cout << ans;
	}
	return 0;
}