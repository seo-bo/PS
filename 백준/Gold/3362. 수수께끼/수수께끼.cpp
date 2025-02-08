#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int k = 0, n = 0;
		cin >> n >> k;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		auto check = [&](int mid)
			{
				vector<int>temp(v.begin(), v.begin() + mid);
				sort(temp.begin(), temp.end());
				int pivot = 0;
				for (auto& i : temp)
				{
					if (pivot >= k || i > pivot + 1)
					{
						break;
					}
					pivot += i;
				}
				return (pivot >= k);
			};
		int left = 1, right = n, ans = -1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (check(mid))
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}