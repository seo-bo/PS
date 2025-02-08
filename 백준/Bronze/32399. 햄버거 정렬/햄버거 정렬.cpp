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
	string ans;
	cin >> ans;
	auto cal = [&]
		{
			if (ans == "1()")
			{
				cout << 1;
			}
			else if (ans == "(1)")
			{
				cout << 0;
			}
			else if (ans == "()1")
			{
				cout << 1;
			}
			else if (ans == "1)(")
			{
				cout << 1;
			}
			else if (ans == ")1(")
			{
				cout << 2;
			}
			else if (ans == ")(1")
			{
				cout << 1;
			}
			else
			{
				cout << -1;
			}
		};
	cal();
	return 0;
}