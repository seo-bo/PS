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
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		if (str[i - 1] == '#' && str[i] == '.' && str[i + 1] == '#')
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
