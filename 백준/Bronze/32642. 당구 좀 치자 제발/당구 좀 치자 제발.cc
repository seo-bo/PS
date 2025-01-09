#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			sum++;
		}
		else
		{
			sum--;
		}
		ans += sum;
	}
	cout << ans;
	return 0;
}