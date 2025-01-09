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
	int cnt = 0;
	for (int i = 0; i < 12; ++i)
	{
		string str;
		cin >> str;
		if (str.size() == i + 1)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
