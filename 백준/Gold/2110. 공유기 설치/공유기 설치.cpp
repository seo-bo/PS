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
	int n = 0, c = 0;
	cin >> n >> c;
	vector<ll>v(n);
	ll ans = 0;
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll left = 1, right = 1e13;
	while (left <= right)
	{
		ll mid = (left + right) / 2, pre = v[0];
		int cnt = 1; // 이미 pre에 하나 설치해둠
		for (int i = 1; i < n; ++i)
		{
			if (v[i] - pre >= mid)
			{
				cnt++;
				pre = v[i];
			}
		}
		if (cnt >= c) // 최대값 구하기니까 하한에다가 ans 투척
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}