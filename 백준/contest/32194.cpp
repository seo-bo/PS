#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>prefix(n + 2, 0);
	prefix[1] = 1;
	for (int i = 2; i <= n + 1; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		bool check = true;
		if (a == 1)
		{
			if (prefix[c] - prefix[b - 1] != c - b + 1)
			{
				check = false;
			}
		}
		else if (a == 2)
		{
			if (prefix[c] - prefix[b - 1])
			{
				check = false;
			}
		}
		if (check)
		{
			cout << yes << '\n';
			prefix[i] = prefix[i - 1] + 1;
		}
		else
		{
			cout << no << '\n';
			prefix[i] = prefix[i - 1];
		}
	}
	return 0;
}
