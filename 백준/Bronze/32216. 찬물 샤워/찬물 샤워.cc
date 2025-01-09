#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0, t = 0;
	cin >> n >> k >> t;
	vector<int>d(n);
	for (auto& i : d)
	{
		cin >> i;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (t < k)
		{
			t = t + d[i] + abs(t - k);
		}
		else if (t > k)
		{		
			t = t + d[i] - abs(t - k);
		}
		else
		{
			t = t + d[i];
		}
		ans += abs(t - k);
	}
	cout << ans;
	return 0;
}