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
	string str;
	cin >> str;
	if (str.size() < 3)
	{
		cout << no;
		return 0;
	}
	int len = str.size() - 1;
	if (str[len] == 'n' && str[len - 1] == 'a' && str[len - 2] == 's')
	{
		cout << yes;
	}
	else
	{
		cout << no;
	}
	return 0;
}
