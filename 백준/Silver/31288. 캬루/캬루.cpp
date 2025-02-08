#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int num = 0;
string str = "";
void check()
{
	if (str.length() == 1)
	{
		cout << 6 << " " << 3 << "\n";
		return;
	}
	ll sum = 0;
	for (auto& i : str)
	{
		sum += (i - '0');
	}
	int tr = sum % 3;
	tr = (3 - tr);
	int siz = str.length();
	for (int i = siz - 1; i >= 0; --i)
	{
		string temp = str;
		int tp = (temp[i] - '0') + tr;
		if (tp > 9)
		{
			tp -= 3;
		}
		temp[i] = tp + '0';
		cout << temp << " " << 3 << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		cin >> num >> str;
		check();
	}
}