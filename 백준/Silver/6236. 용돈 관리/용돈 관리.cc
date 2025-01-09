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
	int n = 0, m = 0;
	cin >> n >> m;
	ll ans = 0;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	ll left = 1, right = INT_MAX;
	while (left <= right)
	{
		ll mid = (left + right) / 2, now = mid;
		int cnt = 1;
		bool check = true;
		for (auto& i : v)
		{
			if (i > mid)
			{
				check = false;
				break;
			}
			if (i > now)
			{
				now = mid;
				cnt++;
			}
			now -= i;
		}
		if (!check || cnt > m)
		{
			
			left = mid + 1;
		}
		else // 최소니까 상한 낮추기로 답 찾기
		{
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}