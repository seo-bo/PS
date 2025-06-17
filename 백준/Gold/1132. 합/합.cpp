#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>per(10, 0);
	iota(per.begin(), per.end(), 0);
	ll ans = 0;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	do
	{
		ll sum = 0;
		for (auto& i : v)
		{
			ll temp = 0;
			if (per[i.front() - 'A'] == 0)
			{
				sum = 0;
				break;
			}
			for (auto& j : i)
			{
				temp = temp * 10 + per[j - 'A'];
			}
			sum += temp;
		}
		ans = max(ans, sum);
	} while (next_permutation(per.begin(), per.end()));
	cout << ans;
	return 0;
}