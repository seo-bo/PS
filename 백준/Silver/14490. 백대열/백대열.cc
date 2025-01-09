#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int idx = str.find(':');
	int a = stoi(str.substr(0, idx));
	int b = stoi(str.substr(idx + 1, str.length() - idx - 1));
	int GCD = gcd(a, b);
	cout << a / GCD << ':' << b / GCD;
	return 0;
}