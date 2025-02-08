#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 시뮬레이션은 못돌리는데, 적절한 분할을 생각하는건가?
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll left = 1, right = (1LL << 60), ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (auto& i : v)
		{
			pivot += mid / i;
			if (pivot >= m)
			{
				break;
			}
		}
		if (pivot >= m)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}