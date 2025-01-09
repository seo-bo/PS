#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tl;
typedef tuple<int, int, int>tp;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		string str;
		cin >> str;
		bool check = false;
		for (int i = 0; i < n; ++i)
		{
			if (str[i] == '1')
			{
				if (i == 0 || i == n - 1)
				{
					check = true;
					break;
				}
				if (str[i - 1] == '1' || str[i + 1] == '1')
				{
					check = true;
					break;
				}
			}
		}
		if (check)
		{
			cout << yes << '\n';
		}
		else
		{
			cout << no << '\n';
		}
	}
	return 0;
}
