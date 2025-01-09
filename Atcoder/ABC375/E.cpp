#include <bits/stdc++.h>
#include <unordered_set>
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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	ll sum = 0;
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		sum += b;
	}
	if (sum % 3)
	{
		cout << -1;
		return 0;
	}
	int pivot = sum / 3;
	int siz = pivot + 2;
	vector<vector<int>>dp(2, vector<int>(siz * siz, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		fill(dp[1].begin(), dp[1].end(), -1);
		for (int j = 0; j <= pivot; ++j)
		{
			for (int k = 0; k <= pivot; ++k)
			{
				int pre = j * (pivot + 1) + k;
				int cur = dp[0][pre];
				if (cur == -1)
				{
					continue;
				}
				int value = j + v[i].second;
				if (value <= pivot)
				{
					int cost = cur + (v[i].first == 1);
					int idx = value * (pivot + 1) + k;
					dp[1][idx] = max(dp[1][idx], cost);
				}
				value = k + v[i].second;
				if (value <= pivot)
				{
					int cost = cur + (v[i].first == 2);
					int idx = j * (pivot + 1) + value;
					dp[1][idx] = max(dp[1][idx], cost);
				}
				int cost = cur + (v[i].first == 3);
				int idx = j * (pivot + 1) + k;
				dp[1][idx] = max(dp[1][idx], cost);
			}
		}
		swap(dp[0], dp[1]);
	}
	int idx = pivot * (pivot + 1) + pivot;
	if (dp[0][idx] == -1)
	{
		cout << -1;
	}
	else
	{
		cout << n - dp[0][idx];
	}
	return 0;
}
