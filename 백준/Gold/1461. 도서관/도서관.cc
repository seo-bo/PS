#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>left, right;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp < 0)
		{
			left.push_back(abs(temp));
		}
		else
		{
			right.push_back(abs(temp));
		}
	}
	sort(left.begin(), left.end(), greater<int>());
	sort(right.begin(), right.end(), greater<int>());
	ll ans = 0;
	for (int i = 0; i < left.size(); i += m)
	{
		ans += left[i] * 2;
	}
	for (int i = 0; i < right.size(); i += m)
	{
		ans += right[i] * 2;
	}
	if (!left.empty() && !right.empty())
	{
		ans -= max(left[0], right[0]);
	}
	else if (!left.empty())
	{
		ans -= left[0];
	}
	else if (!right.empty())
	{
		ans -= right[0];
	}
	cout << ans;
	return 0;
}