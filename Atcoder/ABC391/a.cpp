#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, string>mm = { {"N","S"},{"S","N"},{"E","W"},{"W","E"},
		{"SE","NW"},{"NW","SE"},{"NE","SW"},{"SW","NE"} };
	string str;
	cin >> str;
	cout << mm[str];
	return 0;
}
