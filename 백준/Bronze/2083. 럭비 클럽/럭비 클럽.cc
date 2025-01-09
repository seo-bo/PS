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
	while (1)
	{
		string str;
		cin >> str;
		cin.ignore();
		int a = 0, b = 0;
		cin >> a >> b;
		if (str == "#" && !a && !b)
		{
			break;
		}
		cout << str << ' ';
		if (a > 17 || b >= 80)
		{
			cout << "Senior" << '\n';
		}
		else
		{
			cout << "Junior" << '\n';
		}
	}
	return 0;
}