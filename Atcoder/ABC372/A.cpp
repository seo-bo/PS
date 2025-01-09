#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	string str;
	cin >> str;
	string ans;
	for (auto& i : str)
	{
		if (i == '.')
		{
			continue;
		}
		ans += i;
	}
	cout << ans;
	return 0;
}
