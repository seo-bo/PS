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
	int T = 0;
	cin >> T;
	for (int _ = 1; _ <= T; ++_)
	{
		int a = 0, k = 0;
		cin >> a >> k;
		int mask = (1LL << a) - 1LL;
		string ans;
		if((k & mask) == mask)
		{
			ans = "ON";
		}
		else
		{
			ans = "OFF";
		}
		cout << "Case #" << _ << ": " << ans << '\n';
	}
	return 0;
}