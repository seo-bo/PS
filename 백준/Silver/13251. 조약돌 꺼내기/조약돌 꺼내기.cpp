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
	int n = 0;
	cin >> n;
	lb sum = 0, ans = 0, k = 0;
	vector<lb>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	cin >> k;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] >= k)
		{
			lb temp = 1;
			for (int j = 0; j < k; ++j)
			{
				temp *= (v[i] - (lb)j) / (sum - (lb)j);
			}
			ans += temp;
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}