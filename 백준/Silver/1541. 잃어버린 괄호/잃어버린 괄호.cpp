#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str, temp;
	cin >> str;
	int ans = 0;
	bool check = false;
	for (int i = 0; i < str.length(); ++i)
	{
		if (!check)
		{
			if (str[i] == '-')
			{
				ans += stoi(temp);
				temp = "";
				check = true;
			}
			else if (str[i] == '+')
			{
				ans += stoi(temp);
				temp = "";
			}
			else
			{
				temp += str[i];
			}
		}
		else
		{
			if (str[i] == '-' || str[i] == '+')
			{
				ans -= stoi(temp);
				temp = "";
			}
			else
			{
				temp += str[i];
			}
		}
	}
	cout << ((check) ? (ans - stoi(temp)) : (ans + stoi(temp)));
	return 0;
}