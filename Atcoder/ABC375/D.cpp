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
	string str;
	cin >> str;
	int len = str.length();
	vector<vector<int>>alpha(26);
	for (int i = 0; i < len; ++i)
	{
		alpha[str[i] - 'A'].push_back(i + 1);
	}
	ll ans = 0;
	for (int i = 0; i < 26; ++i)
	{
		int p = alpha[i].size();
		if (p < 2)
		{
			continue;
		}
		vector<ll>prefix(p + 1, 0);
		for (int j = 1; j <= p; ++j)
		{
			prefix[j] = prefix[j - 1] + alpha[i][j - 1];
		}
		for (int j = 1; j < p; ++j)
		{
			ans += 1LL * j * alpha[i][j] - prefix[j] - (1LL * j);
		}
	}
	cout << ans;
	return 0;
}
