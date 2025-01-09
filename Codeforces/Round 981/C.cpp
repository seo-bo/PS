#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		vector<ll>dp(2, 0);
		int left = 0, right = n - 1;
		while (left + 1 <= right - 1)
		{
			vector<ll>temp(2, INT_MAX);
			temp[0] = min(dp[0] + (v[left] == v[left + 1]) + (v[right] == v[right - 1]), dp[1] + (v[left] == v[right - 1]) + (v[right] == v[left + 1]));
			temp[1] = min(dp[1] + (v[left] == v[left + 1]) + (v[right] == v[right - 1]), dp[0] + (v[left] == v[right - 1]) + (v[right] == v[left + 1]));
			swap(dp, temp);
			left++, right--;
		}
		if (left < right && v[left] == v[right])
		{
			dp[0]++, dp[1]++;
		}
		cout << min(dp[0], dp[1]) << '\n';
	}
	return 0;
}
