#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v(3);
	string str;
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> str;
	int temp = 0;
	if (str == "Red")
	{
		temp = 0;
	}
	else if (str == "Green")
	{
		temp = 1;
	}
	else
	{
		temp = 2;
	}
	int ans = INT_MAX;
	for (int i = 0; i < 3; ++i)
	{
		if (i == temp)
		{
			continue;
		}
		ans = min(ans, v[i]);
	}
	cout << ans;
	return 0;
}
