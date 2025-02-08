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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0, b = 0;
	cin >> n >> k >> b;
	vector<int>v(n + 1, 0);
	for (int i = 0; i < b; ++i)
	{
		int temp = 0;
		cin >> temp;
		v[temp]++;
	}
	int sum = 0;
	for (int i = 1; i <= k; ++i)
	{
		sum += v[i];
	}
	int ans = sum;
	for (int left = 1, right = k + 1; right <= n; ++left, ++right)
	{
		sum += v[right];
		sum -= v[left];
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}