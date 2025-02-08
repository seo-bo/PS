#include <bits/stdc++.h>
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
	int a = 0, b = 0, ans = 0;
	cin >> a >> b;
	if (!(a % 2))
	{
		ans++;
	}
	if (b % 2)
	{
		ans++;
	} 
	cout << (b - a - ans + 1) / 2 + ans;
	return 0;
}