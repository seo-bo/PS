#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, maxi = 0;
	cin >> n;
	vector<int>factor(2000002, 0), visited(2000002, 0);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		visited[temp]++;
	}
	ll ans = 0;
	for (int i = 1; i <= 2000000; ++i)
	{
		for (int j = i; j <= 2000000; j += i)
		{
			factor[i] += visited[j];
		}
		if (factor[i] < 2)
		{
			continue;
		}
		ans = max(ans, (ll)i * (ll)factor[i]);
	}
	cout << ans;
	return 0;
}