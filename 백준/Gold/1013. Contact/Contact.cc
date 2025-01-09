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
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		regex p("(100+1+|01)+");
		cout << (regex_match(str, p) ? "YES" : "NO") << '\n';
	}
	return 0;
}