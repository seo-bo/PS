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
	int T = 0;
	cin >> T;
	unordered_set<string>a;
	while (T--)
	{
		string str;
		cin >> str;
		int len = str.length();
		if (len < 6)
		{
			continue;
		}
		if (str.substr(len - 6, 6) == "Cheese")
		{
			a.insert(str);
		}
	}
	if (a.size() >= 4)
	{
		cout << "yummy";
	}
	else
	{
		cout << "sad";
	}
	return 0;
}