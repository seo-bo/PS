#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		swap(s1[0], s2[0]);
		cout << s1 << ' ' << s2 << '\n';
	}
	return 0;
}
