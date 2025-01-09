#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	bool check = regex_match(str, regex("(100+1+|01)+"));
	cout << (check ? "SUBMARINE" : "NOISE");
	return 0;
}