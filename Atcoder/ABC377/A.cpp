#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	cout << ((str == "ABC") ? "Yes" : "No");
	return 0;
}
