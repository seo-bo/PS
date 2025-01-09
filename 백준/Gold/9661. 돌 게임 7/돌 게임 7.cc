#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 직접 그런디수 구하기!?
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	cout << ((n % 5 == 0 || n % 5 == 2) ? "CY" : "SK");
	return 0;
}