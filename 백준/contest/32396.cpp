#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	vector<ll>v(n);
	vector<bool>visited(n, false);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (llabs(v[i] - v[i - 1]) < m)
		{
			if (!visited[i - 1])
			{
				ans++;
				visited[i] = true;
			}
		}
	}
	cout << ans;
	return 0;
}
