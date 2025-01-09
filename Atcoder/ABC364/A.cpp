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
	string prev = "asd";
	int n = 0;
	cin >> n;
	bool check = false;
	bool acheck = false;
	for (int i = 0; i < n; ++i)
	{
		if (check)
		{
			acheck = true;
			break;
		}
		string temp;
		cin >> temp;
		if (temp == "sweet" && prev == "sweet")
		{
			if (!check)
			{
				check = true;
			}
		}
		prev = temp;
	}
	if (acheck)
	{
		cout << no;
	}
	else
	{
		cout << yes;
	}
	return 0;
}
