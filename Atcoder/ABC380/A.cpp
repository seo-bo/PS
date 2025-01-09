#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	map<char, int>mm;
	for (auto& i : str)
	{
		mm[i]++;
	}
	if (mm['1'] == 1 && mm['2'] == 2 && mm['3'] == 3)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
