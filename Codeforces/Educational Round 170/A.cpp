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
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		int len = min(s.size(), t.size()), pivot = 0;
		for (int i = 1; i <= len; ++i)
		{
			if (s.substr(0, i) == t.substr(0, i))
			{
				pivot = i;
			}
		}
		int ans = s.size() + t.size();
		ans = min(ans, ans - (pivot > 0 ? pivot - 1 : 0));
		cout << ans << '\n';
	}
	return 0;
}
