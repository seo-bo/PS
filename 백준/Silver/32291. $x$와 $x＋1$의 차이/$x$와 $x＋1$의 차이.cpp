#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll x = 0;
	cin >> x;
	x++;
	vector<ll>ans;
	for (ll i = 1; i * i <= x; ++i)
	{
		if (!(x % i))
		{
			ans.push_back(i);
			if (i != x / i && i != 1)
			{
				ans.push_back(x / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}