#include <bits/stdc++.h>
#include <unordered_set>
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
	vector<int>al(26, 0);
	for (int i = 0; i < 26; ++i)
	{
		al[str[i] - 'A'] = i;
	}
	ll ans = 0;
	int idx = al[0];
	for (int i = 1; i < 26; ++i)
	{
		ans += abs(al[i] - idx);
		idx = al[i];
	}
	cout << ans;
	return 0;
}
