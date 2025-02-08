#include <bits/stdc++.h>
#include <unordered_set>
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
	string s, t;
	cin >> s >> t;
	while (t.length() != s.length())
	{
		if (t.back() == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	cout << (t == s);
	return 0;
}