#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	auto level = [&](ll exp)
		{
			ll left = 0, right = 1e9;
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if ((mid * mid) + mid <= exp)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			return left;
		};
	for (int i = 0; i < T; ++i)
	{
		ll temp = 0;
		cin >> temp;
		ll exp = temp * (temp + 1) / 2;
		cout << level(exp) << "\n";
	}
	return 0;
}