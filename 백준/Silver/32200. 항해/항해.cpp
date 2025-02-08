#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, x = 0, y = 0, cnt = 0, ans = 0, pivot = 0, temp =0 ;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp < x)
		{
			ans += temp;
			continue;
		}
		pivot = temp / x;
		cnt += pivot;
		if (temp > pivot * y)
		{
			ans += temp % y;
		}
	}
	cout << cnt << '\n' << ans;
	return 0;
}