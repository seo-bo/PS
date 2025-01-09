#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int left = 0, right = n - 1;
	ll ans = LLONG_MAX;
	while (left < right)
	{
		ll sum = v[left] + v[right];
		if (llabs(sum) < llabs(ans))
		{
			ans = sum;
		}
		if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	cout << ans;
	return 0;
}