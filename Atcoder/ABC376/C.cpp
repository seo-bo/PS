#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll left = 1, right = 0, ans = -1;
	vector<ll>a(n), b(n - 1);
	for (auto& i : a)
	{
		cin >> i;
		right = max(right, i);
	}
	for (auto& i : b)
	{
		cin >> i;
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	auto cal = [&](ll mid)
		{
			int idx = 0, fail = 0;
			for (int i = 0; i < n; ++i)
			{
				if (idx < n - 1 && b[idx] >= a[i])
				{
					idx++;
				}
				else
				{
					if (mid >= a[i] && !fail)
					{
						fail++;
					}
					else
					{
						return false;
					}
				}
			}
			return true;
		};
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (cal(mid))
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
