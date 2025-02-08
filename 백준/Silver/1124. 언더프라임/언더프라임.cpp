#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<bool>v(100002, true);
	v[0] = false, v[1] = false;
	for (int i = 2; i <= sqrt(100000); ++i)
	{
		if (v[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				v[j] = false;
			}
		}
	}
	vector<int>pr;
	for (int i = 2; i <= 100000; ++i)
	{
		if (v[i])
		{
			pr.push_back(i);
		}
	}
	int a = 0, b = 0, ans = 0;
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
	{
		int temp = i;
		int cnt = 0;
		for (auto& k : pr)
		{
			if (temp == 1)
			{
				break;
			}
			while (!(temp % k))
			{
				temp /= k;
				cnt++;
			}
		}
		if (v[cnt])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}