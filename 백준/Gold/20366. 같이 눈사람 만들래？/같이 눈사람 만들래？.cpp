#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll ans = LLONG_MAX;
	auto check = [&](int pos, int i, int j)
		{
			if (pos == i || pos == j)
			{
				return false;
			}
			return true;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ll a = v[i] + v[j], temp = LLONG_MAX;
			int left = 0, right = n - 1;
			while (left < right)
			{
				if (!check(left, i, j))
				{
					left++;
					continue;
				}
				if (!check(right, i, j))
				{
					right--;
					continue;
				}
				ll pivot = a - (v[left] + v[right]);
				temp = min(temp, llabs(pivot));
				if (pivot < 0)
				{
					right--;
				}
				else
				{
					left++;
				}
			}
			ans = min(ans, temp);
		}
	}
	cout << ans;
	return 0;
}