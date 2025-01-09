#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>mi(4, 0), ma(4, 0);
	for (int i = 1; i <= n; ++i)
	{
		vector<int>v(4);
		for (int k = 1; k <= 3; ++k)
		{
			cin >> v[k];
		}
		vector<int>tmi(4), tma(4);
		tmi[1] = min(mi[1], mi[2]) + v[1];
		tmi[2] = min({ mi[1],mi[2],mi[3] }) + v[2];
		tmi[3] = min(mi[2], mi[3]) + v[3];
		tma[1] = max(ma[1], ma[2]) + v[1];
		tma[2] = max({ ma[1],ma[2],ma[3] }) + v[2];
		tma[3] = max(ma[2], ma[3]) + v[3];
		mi = tmi, ma = tma;
	}
	cout << *max_element(ma.begin() + 1, ma.end()) << ' ' << *min_element(mi.begin() + 1, mi.end());
	return 0;
}